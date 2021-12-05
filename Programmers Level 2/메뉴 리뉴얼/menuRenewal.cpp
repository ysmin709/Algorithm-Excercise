#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    sort(orders.begin(), orders.end());
    
    for (int i = 0; i < course.size(); i++) {
        map<string, int> m;
        
        for (int j = 0; j < orders.size(); j++) {
            if (orders[j].size() >= course[i]) {
                // 정해진 코스의 수만큼만 세트로 순열 생성
                vector<int> check;
                for (int k = 0; k < course[i]; k++) check.push_back(1); 
                for (int k = 0; k < orders[j].size() - course[i]; k++) check.push_back(0);

                sort(check.begin(), check.end());

                do {
                    string temp = "";
                    for (int k = 0; k < check.size(); k++) {
                        if (check[k]) temp += orders[j][k];
                    }
                    sort(temp.begin(), temp.end());
                    m[temp]++; // 주문된 코스의 횟수를 증가
                }while(next_permutation(check.begin(), check.end()));
            }
        }
        
        vector<pair<string, int>> res(m.begin(), m.end()); // 가장 많이 주문된 구성을 알기 위해 map 정보를 vector로 이동 
        sort(res.begin(), res.end(), cmp); // value를 기준으로 내림차순 sort
        
        int max = 0;
        if (!res.empty()) max = res[0].second; // res가 비어있지 않으면 제일 큰 값을 max로 설정
        
        if (max > 1) { // 제일 큰 값이 2 이상일 때만 동작
            for (int j = 0; j < res.size(); j++) {
                if (res[j].second == max) answer.push_back(res[j].first); // max와 횟수가 같은 구성을 answer에 추가
                else break;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}