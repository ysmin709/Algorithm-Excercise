#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    string str;
    cin >> str;

    stack<char> stk;
    int answer = 0, temp = 1;
    bool check = true;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            stk.push(str[i]);
            temp *= 2;
        }
        else if (str[i] == ')') {
            if (stk.empty() || stk.top() != '(') {
                check = false;
                break;
            }
            else {
                if (str[i - 1] == '(') answer += temp;
                stk.pop();
                temp /= 2;                
            }
        }
        else if (str[i] == '[') {
            stk.push(str[i]);
            temp *= 3;
        }
        else if (str[i] == ']') {
            if (stk.empty() || stk.top() != '[') {
                check = false;
                break;
            }
            else {
                if (str[i - 1] == '[') answer += temp;
                stk.pop();
                temp /= 3;
            }
        }
    }
    
    if (!check || !stk.empty()) cout << "0\n";
    else cout << answer << "\n";
}