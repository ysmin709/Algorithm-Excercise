#include <cstdio>
#include <vector>
using namespace std;

int n, answer = 0;
int arr[100][100];
long long dp[100][100];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!arr[i][j]) continue;
            if (dp[i][j] != 0) {
                int nx = j + arr[i][j];
                int ny = i + arr[i][j];

                if (nx < n) dp[i][nx] += dp[i][j]; // 아래 방향으로 체크
                if (ny < n) dp[ny][j] += dp[i][j]; // 오른쪽 방향으로 체크
            }
        }
    }

    printf("%lld\n", dp[n-1][n-1]);
}