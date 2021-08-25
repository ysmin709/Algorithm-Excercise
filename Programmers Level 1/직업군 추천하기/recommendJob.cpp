#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, int> m;
    
    for (int i = 0; i < table.size(); i++) {
        stringstream ss;
        ss.str(table[i]);
        string job = "";
        ss >> job; // 직군은 미리 분리
        
        for (int i = 0; i < 5; i++) {
            string temp = "";
            ss >> temp;
            for (int j = 0; j < languages.size(); j++) {
                if (temp == languages[j]) m[job] += preference[j] * (5 - i); // 해당 직군에 지정된 언어가 있으면 직군을 map에 key값으로 지정하고 value 값을 순위와 언어선호도를 고려하여 증가시킨다.
            }
        }
    }
    
    int max = 0;
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) { // map의 처음부터 끝까지 체크
        if (it->second > max) { max = it->second; answer = it->first; } // map은 사전순으로 정렬되기 때문에 value가 max보다 클 때만 최신화한다.
    }
    
    return answer;
}