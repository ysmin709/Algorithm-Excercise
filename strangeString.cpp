#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int j = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (j % 2 == 0) s[i] -= 32;
            j++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            if (j % 2 == 1) s[i] += 32;
            j++;
        }
        else j = 0;
    }
    
    answer = s;
    return answer;
}