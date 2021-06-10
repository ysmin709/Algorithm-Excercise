#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    vector<char> temp;
    
    for (int i = 0; i < s.size(); i++) temp.push_back(s[i]);
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == ' ') continue;
        for (int j = 1; j <= n; j++) {
            temp[i]++;
            if (temp[i] == 'Z'+1) temp[i] = 'A';
            else if (temp[i] == 'z'+1) temp[i] = 'a';
        }
    }
    for (int i = 0; i < temp.size(); i++) answer += temp[i];
    
    return answer;
}