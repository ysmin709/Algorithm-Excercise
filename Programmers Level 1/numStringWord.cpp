#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') temp += s[i];
        else {
            switch(s[i]) {
                case 'z':
                    temp += '0';
                    i += 3;
                    break;
                case 'o':
                    temp += '1';
                    i += 2;
                    break;
                case 't':
                    if (s[i+1] == 'w') { temp += '2'; i += 2; break; }
                    else { temp += '3'; i += 4; break; }
                case 'f':
                    if (s[i+1] == 'o') { temp += '4'; i += 3; break; }
                    else { temp += '5'; i += 3; break; }
                case 's':
                    if (s[i+1] == 'i') { temp += '6'; i += 2; break; }
                    else { temp += '7'; i += 4; break; }
                case 'e':
                    temp += '8';
                    i += 4;
                    break;
                case 'n':
                    temp += '9';
                    i += 3;
                    break;
            }
        }
    }
    
    answer = stoi(temp);
    
    return answer;
}