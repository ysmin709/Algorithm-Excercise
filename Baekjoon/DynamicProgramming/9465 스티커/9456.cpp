#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<vector<int>> vec(2, vector<int>(n, 0));
        vector<vector<int>> dp(vec.begin(), vec.end());
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) cin >> vec[j][k];
        }
        dp[0][0] = vec[0][0];
        dp[1][0] = vec[1][0];
        dp[0][1] = vec[0][1] + dp[1][0];
        dp[1][1] = vec[1][1] + dp[0][0];

        for (int j = 2; j < n; j++) {
            dp[0][j] = vec[0][j] + max(dp[1][j-1], dp[1][j-2]);
            dp[1][j] = vec[1][j] + max(dp[0][j-1], dp[0][j-2]);
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }
}