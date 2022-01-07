#include <cstdio>
#include <vector>
using namespace std;

int n, m;
bool answer = false;
char arr[1001][1001];
bool visited[1001][1001];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y) {
    visited[x][y] = true;
    if (x == n-1) { answer = true; return; } // 목표 지점에 도착

    for (int i = 0; i < 4; i++) { // 4방향 체크
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (arr[nx][ny] == '0' && !visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%s", &arr[i]);

    for (int i = 0; i < m; i++) {
        if (arr[0][i] == '0' && !visited[0][i] && !answer) dfs(0, i); // 제일 윗 칸만 체크
    }

    if (answer) printf("%s", "YES");
    else printf("%s", "NO");
}