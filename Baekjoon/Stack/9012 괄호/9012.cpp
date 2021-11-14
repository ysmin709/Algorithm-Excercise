#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string temp = "";
        cin >> temp;
        stack<char> stk;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == '(') stk.push(temp[j]);
            else {
                if (!stk.empty()) stk.pop();
                else { stk.push(')'); break; }
            }
        }

        if (stk.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}