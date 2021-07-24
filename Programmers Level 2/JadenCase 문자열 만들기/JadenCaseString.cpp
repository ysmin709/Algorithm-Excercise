#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' && i < s.size()-1) {
            answer += s[i];
            if (s[i+1] >= 'a' && s[i+1] <= 'z') { answer += toupper(s[i+1]); }
            else if (s[i+1] == ' ') continue;
            else answer += s[i+1];
            i++;
        }
        else if (i == 0) {
            if (s[i] >= 'a' && s[i] <= 'z') answer += toupper(s[i]);
            else answer += s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') answer += tolower(s[i]);
        else answer += s[i];
    }    
    
    return answer;
}