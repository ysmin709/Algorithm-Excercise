#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;

    vector<vector<int>> dp(1001, vector<int>(10, 0));

    for (int i = 0; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) answer += dp[n][i];
    answer %= 10007;

    cout << answer << endl;
}