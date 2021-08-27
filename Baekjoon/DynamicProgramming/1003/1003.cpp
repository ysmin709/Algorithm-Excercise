#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<pair<int, int>> dp(n+1, make_pair(0, 0));
        dp[0] = make_pair(1, 0);
        dp[1] = make_pair(0, 1);

        for (int i = 2; i <= n; i++) {
            dp[i].first = dp[i-1].first + dp[i-2].first;
            dp[i].second = dp[i-1].second + dp[i-2].second;
        }
        cout << dp[n].first << " " << dp[n].second << endl;
    }
}