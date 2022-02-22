#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int t, n;
    string p, arr;

    cin >> t;

    while(t--) {
        cin >> p >> n >> arr;

        deque<int> dq;
        string temp = "";
        bool check = true, reverse = false;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= '0' && arr[i] <= '9') temp += arr[i];
            else {
                if (temp.size() != 0) dq.push_back(stoi(temp));
                temp = "";
            }
        }

        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                if (reverse) reverse = false;
                else reverse = true;
            }
            else if (p[i] == 'D') {
                if (dq.empty()) { 
                    cout << "error\n";
                    check = false;
                    break;
                }
                else {
                    if (reverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }

        if (check) {
            if (!dq.empty()) {
                cout << "[";
                if (reverse) {
                    for (int i = dq.size() - 1; i > 0; i--) cout << dq[i] << ",";
                    cout << dq[0] << "]\n";
                }
                else {
                    for (int i = 0; i < dq.size() - 1; i++) cout << dq[i] << ",";
                    cout << dq[dq.size()-1] << "]\n";
                }
            }
            else cout << "[]\n";
        }
    }
}