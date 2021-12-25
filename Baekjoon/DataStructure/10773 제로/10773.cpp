#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k, n, answer = 0;
    cin >> k;

    stack<int> stk;

    for (int i = 0; i < k; i++) {
        cin >> n;
        if (!n) stk.pop();
        else stk.push(n);
    }

    while(!stk.empty()) {
        answer += stk.top();
        stk.pop();
    }

    cout << answer << endl;
}