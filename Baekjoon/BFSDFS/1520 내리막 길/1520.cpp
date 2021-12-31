#include <cstdio>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> arr(501, vector<int>(501, 0));
vector<vector<int>> dp(501, vector<int>(501, -1));
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int dfs(int x, int y) {
    if (x == 1 && y == 1) return 1;
    if (dp[x][y] == -1) {
        dp[x][y] = 0; // 방문 표시

        for (int i = 0; i < 4; i++) { // 4방향 체크
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= m && ny > 0 && ny <= n) {
                if (arr[nx][ny] > arr[x][y]) dp[x][y] += dfs(nx, ny); // 모든 경우의 수를 찾는데 시간이 많이 걸리기 때문에 dp 사용
            }
        }
    }

    return dp[x][y];
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) scanf("%d", &arr[i][j]);
    }

    printf("%d\n", dfs(m, n));
}