#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    vector<char> vec;
    stack<int> stk;

    int n, cnt = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        while (cnt <= temp) {
            stk.push(cnt);
            cnt++;
            vec.push_back('+');
        }

        if (stk.top() == temp) {
            stk.pop();
            vec.push_back('-');
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 0; i < vec.size(); i++) cout << vec[i] << "\n";
}