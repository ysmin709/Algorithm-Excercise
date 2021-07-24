#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;
    stack<char> stk;
        
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push(s[i]);
        else {
            if (stk.size() >= 1) stk.pop();
            else return false;
        }
    }
    
    if (!stk.empty()) answer = false;
    return answer;
}