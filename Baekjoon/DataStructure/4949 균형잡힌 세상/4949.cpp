#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    string temp;

	while(true) {
        getline(cin, temp);

        stack<char> stk;
        bool check = true;

        if (temp[0] == '.' && temp.size() == 1) break;

        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i] == '(' || temp[i] == '[') stk.push(temp[i]);
            else if (temp[i] == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else { check = false; break; }
            }
            else if (temp[i] == ']') {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else { check = false; break; }
            }
        }

        if (check && stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }  
}