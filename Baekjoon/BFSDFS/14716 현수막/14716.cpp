#include <cstdio>
using namespace std;

int n, m, answer = 0;
int arr[251][251];
bool visited[251][251];
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) { // 8방향 체크
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (arr[nx][ny] && !visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && !visited[i][j]) {
                dfs(i, j);
                answer++;
            }
        }
    }

    printf("%d", answer);
}