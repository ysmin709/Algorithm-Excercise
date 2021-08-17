#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> stk;
    
    for (int i = 0; i < s.size(); i++) {
        if (stk.empty() || stk.top() != s[i]) stk.push(s[i]); // 스택이 비어있거나 스택의 top이 현재 값과 같을 때 push
        else stk.pop();
    }
    
    if (stk.empty()) return 1; // 스택이 비어있으면 전부 제거한 것이므로 1을 리턴한다.
    else return 0; // 더 이상 제거할 수 없으면 0을 리턴
}