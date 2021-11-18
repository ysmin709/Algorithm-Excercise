#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { // map의 value 기준으로 sort
    if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    
    for (int i = 0; i < s.size(); i++) {
        string temp = ""; // 원소 확인
        if (s[i] >= '0' && s[i] <= '9') {
            while(s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
                i++;
            }
            m[stoi(temp)]++; // 해당 원소의 출현 횟수 증가
        }
    }
    
    vector<pair<int, int>> vec(m.begin(), m.end()); // sort를 진행하기 위해 map 정보를 vector로 가져온다.
    sort(vec.rbegin(), vec.rend(), cmp);
    
    for (int i = 0; i < vec.size(); i++) answer.push_back(vec[i].first); // key 값을 answer vector에 추가한다.
    
    return answer;
}