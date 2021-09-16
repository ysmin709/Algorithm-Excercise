#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    
    vector<pair<double, pair<int, int>>> vec; // 승률, 자신의 번호, 자신보다 무거운 복서를 이긴 횟수를 저장하기 위한 vector
    
    for (int i = 0; i < head2head.size(); i++) {
        double win = 0, lose = 0;
        int heavy = 0;
        for (int j = 0; j < head2head[i].size(); j++) {
            if (head2head[i][j] == 'L') lose++;
            else if (head2head[i][j] == 'W') {
                win++;
                if (weights[i] < weights[j]) heavy++;
            }
        }
        if (win == 0 && lose == 0) vec.push_back(make_pair(0, make_pair(i, heavy))); // 전적이 없는 복서 저장
        else vec.push_back(make_pair(win / (lose + win), make_pair(i, heavy)));
    }
    
    sort(vec.rbegin(), vec.rend()); // 승률을 기준으로 내림차순 정렬
    
    for (int i = 0; i < weights.size() - 2; i++) { // 버블정렬 사용
        for (int j = 1; j < weights.size() - i; j++) {
            if (vec[j].first == vec[j-1].first) { // 승률이 같을 때
                if (vec[j].second.second > vec[j-1].second.second) vec[j].swap(vec[j-1]);
                else if (vec[j].second.second == vec[j-1].second.second) { // 자신보다 무거운 복서를 이긴 횟수가 같을 때
                    if (weights[vec[j].second.first] > weights[vec[j-1].second.first]) vec[j].swap(vec[j-1]);
                    else if (weights[vec[j].second.first] == weights[vec[j-1].second.first]) { // 몸무게가 같을 때
                        if (vec[j].second.first < vec[j-1].second.first) vec[j].swap(vec[j-1]); // 복서의 번호를 기준으로 정렬
                    }
                }
            }            
        }
    }
    
    for (int i = 0; i < weights.size(); i++) answer.push_back(vec[i].second.first+1);
    
    return answer;
}