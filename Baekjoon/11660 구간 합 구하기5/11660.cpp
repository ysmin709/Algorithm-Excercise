#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> vec(n+1, vector<int>(n+1, 0));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &vec[i][j]);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + vec[i][j] - dp[i-1][j-1]; // dp 배열에 누적합 저장
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]);
    }

 }