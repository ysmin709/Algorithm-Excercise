#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> temp;
            vec[i][j] = temp;
        }
    }

    dp[0][0] = vec[0][0]; // 제일 위 층만 먼저 저장

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = dp[i-1][j] + vec[i][j]; // 제일 왼쪽은 오른쪽 위의 값만 가진다.
            else if (j == i) dp[i][j] = dp[i-1][j-1] + vec[i][j]; // 제일 오른쪽은 왼쪽 위의 값만 가진다.
            else { // 가운데 있는 값들은 자신의 왼쪽 위와 오른쪽 위의 값을 비교하여 큰 값을 가진다.
                dp[i][j] = max(dp[i-1][j-1] + vec[i][j], dp[i-1][j] + vec[i][j]);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (dp[n-1][i] > max) max = dp[n-1][i];
    }

    cout << max << endl;
}