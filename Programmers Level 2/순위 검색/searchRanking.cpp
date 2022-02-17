#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> m;
    
    for (int i = 0; i < info.size(); i++) {
        stringstream ss;
        ss.str(info[i]);
        vector<vector<string>> str(4, vector<string>(2, "-"));
        
        string token;
        int score, index = 0;
        
        while (ss >> token) {
            if(index < 4)  str[index][0] = token;
            else score = stoi(token);
            index++;
        }
        
        for (int i = 0; i < 2; i++) { // query에서 입력 받을 수 있는 '-'가 포함된 모든 경우의 수를 map에 저장
            string t1, t2, t3, t4;
            t1 = str[0][i];
            for (int j = 0; j < 2; j++) {
                t2 = str[1][j];
                for (int k = 0; k < 2; k++) {
                    t3 = str[2][k];
                    for (int l = 0; l < 2; l++) {
                        t4 = str[3][l];
                        m[t1 + t2 + t3 + t4].push_back(score);
                    }
                }
            }
        }
    }
    
    map<string, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++) sort(it->second.begin(), it->second.end()); // 점수를 오름차순으로 정렬
    
    for (int i = 0; i < query.size(); i++) {
        stringstream ss;
        ss.str(query[i]);
        
        string token, str = "";
        int index = 0, score = 0;
        
        while (ss >> token){
            if (token == "and") continue;
            if (index++ < 4) str += token;
            else score = stoi(token);
        }
        
        vector<int>::iterator itt;
        itt = lower_bound(m[str].begin(), m[str].end(), score); // 기준 점수 이상인 부분 중 가장 낮은 점수의 index를 얻기 위해 lower_bound를 사용한다.
        
        answer.push_back(m[str].size() - (itt - m[str].begin())); // 전체 크기 - 기준 점수보다 낮은 값을 answer에 push 한다.
    }
    
    return answer;
}