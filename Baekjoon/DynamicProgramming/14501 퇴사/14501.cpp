#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, answer = 0;
    cin >> n;

    int dp[16] = { 0 }, cost[16] = { 0 }, time[16] = { 0 };

    for (int i = 1; i <= n; i++) {
        cin >> time[i] >> cost[i];

        for (int j = 0; j < i; j++) {
            if (time[j] + j <= i && i + time[i] <= n + 1) dp[i] = max(dp[i], dp[j] + cost[i]);
        }
    }

    for (int i = 0; i <= n; i++) answer = max(answer, dp[i]);

    cout << answer << "\n";
}