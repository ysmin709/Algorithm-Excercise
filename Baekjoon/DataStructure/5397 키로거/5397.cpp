#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string str, result = "";
        cin >> str;

        stack<int> stk, temp;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '<') {
                if (!stk.empty()) {
                    temp.push(stk.top());
                    stk.pop();
                }
            }
            else if (str[i] == '>') {
                if (!temp.empty()) {
                    stk.push(temp.top());
                    temp.pop();
                }
            }
            else if (str[i] == '-') {
                if (!stk.empty()) stk.pop();
            }
            else stk.push(str[i]);
        }
        while (!temp.empty()) {
            stk.push(temp.top());
            temp.pop();
        }
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        reverse(result.begin(), result.end());
        cout << result << "\n";
    }
}