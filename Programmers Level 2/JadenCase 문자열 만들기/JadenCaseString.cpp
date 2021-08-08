#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' && i < s.size()-1) { // 공백 확인
            answer += s[i];
            if (s[i+1] >= 'a' && s[i+1] <= 'z') { answer += toupper(s[i+1]); } // 공백 다음 문자는 대문자로 변환
            else if (s[i+1] == ' ') continue;
            else answer += s[i+1];
            i++;
        }
        else if (i == 0) { // 첫 문자가 대문자인지 확인
            if (s[i] >= 'a' && s[i] <= 'z') answer += toupper(s[i]);
            else answer += s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') answer += tolower(s[i]); // 위에 해당하지 않는 대문자들은 소문자로 변환
        else answer += s[i]; // 변환할 필요가 없으면 바로 append
    }    
    
    return answer;
}