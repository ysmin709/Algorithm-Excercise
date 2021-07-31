#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++) { // string 크기만큼 회전
        stack<char> stk; // 괄호를 저장하는 stack
        int j; // string을 끝까지 확인했는지 체크하기 위해 여기다 j를 선언함
        
        for (j = 0; j < s.size(); j++) { // string의 모든 원소 체크
            if (s[j] == '(' || s[j] == '{' || s[j] == '[') stk.push(s[j]); // 괄호가 열리는 부분은 전부 push한다.
            else {
                if (stk.empty()) break;
                else if ((stk.top() == '(' && s[j] == ')') || (stk.top() == '{' && s[j] == '}') || (stk.top() == '[' && s[j] == ']')) stk.pop(); // 닫히는 괄호는 올바른 괄호를 만나면 pop한다.
            }
        }
        
        if (j == s.size() && stk.empty()) answer++; // j와 stack을 통해 올바른 괄호면 answer를 증가한다.
        
        s += s[0];
        s.erase(s.begin());
    }

    
    return answer;
}