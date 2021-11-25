#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    
    for (int i = 0; i < 26; i++) { // 알파벳 대문자는 사전에 미리 등록
        string temp = "";
        temp += 'A' + i;
        m[temp] = i + 1;
    }
    
    int num = 27; // 26개가 등록 됐으므로 27부터 시작
    for (int i = 0; i < msg.size(); i++) {
        string temp = "";
        temp += msg[i];
        
        int j = 1;
        while(true) {
            temp += msg[i+j]; // 다음 문자 append
            if (!m[temp]) { // 사전에 등록되지 않은 문자열이라면
                m[temp] = num; // 사전에 등록
                num++;
                temp.erase(temp.size()-1, 1); // 문자를 append한 상태로 비교 했으므로 끝부분 erase
                answer.push_back(m[temp]);
                i += j - 1; // for문에서 i가 ++되므로 -1
                break;
            }
            j++;
        }
    }
    
    return answer;
}