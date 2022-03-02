#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, idx, answer = 0;
        cin >> n >> idx;

        deque<int> dq(n);

        for (int i = 0; i < n; i++) cin >> dq[i];

        deque<int> temp(dq.begin(), dq.end());
        sort(temp.rbegin(), temp.rend());

        while (true) {
            if (idx == 0 && temp[0] == dq[idx]) {
                answer++;
                break;
            }
            else if (temp[0] == dq[0]) {
                temp.pop_front();
                dq.pop_front();
                idx--;
                answer++;
            }
            else if (idx == 0 && temp[0] != dq[idx]) {
                dq.push_back(dq[0]);
                dq.pop_front();
                idx = dq.size() - 1;
            }
            else if (temp[0] != dq[0]) {
                dq.push_back(dq.front());
                dq.pop_front();
                idx--;
            }
        }

        cout << answer << "\n";
    }
}