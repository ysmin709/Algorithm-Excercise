#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    if (s[0] == '+') {
        s.at(0);
        answer = stoi(s);
    }
    else if (s[0] == '-') {
        s.at(0);
        answer = stoi(s);
    }
    else answer = stoi(s);
    
    return answer;
}