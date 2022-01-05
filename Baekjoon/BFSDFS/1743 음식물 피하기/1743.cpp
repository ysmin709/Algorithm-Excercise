#include <cstdio>
#include <vector>
using namespace std;

int n, m, k, area = 0;
bool arr[101][101];
bool visited[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(pair<int, int> node) {
    visited[node.first][node.second] = true;
    area++;

    for (int i = 0; i < 4; i++) { // 4방향 체크
        int nx = node.first + dx[i];
        int ny = node.second + dy[i];

        if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
            if (arr[nx][ny] && !visited[nx][ny]) dfs(make_pair(nx, ny));
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        arr[r][c] = true;
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] && !visited[i][j]) {
                dfs(make_pair(i, j));
                answer = max(answer, area); // 가장 큰 넓이를 가진 음식물 체크
                area = 0;
            }
        }
    }

    printf("%d\n", answer);
}