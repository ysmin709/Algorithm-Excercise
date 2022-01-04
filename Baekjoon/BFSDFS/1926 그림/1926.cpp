#include <cstdio>
#include <vector>
using namespace std;

int n, m, area = 0;
bool arr[501][501];
bool visited[501][501];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(pair<int, int> node) {
    visited[node.first][node.second] = true;
    area++;

    for (int i = 0; i < 4; i++) { // 4방향 체크
        int nx = node.first + dx[i];
        int ny = node.second + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (arr[nx][ny] && !visited[nx][ny]) dfs(make_pair(nx, ny));
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
    }

    int answer = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && !visited[i][j]) {
                cnt++; // 그림의 개수 증가
                dfs(make_pair(i, j));
                answer = max(answer, area); // 가장 큰 넓이를 가진 그림 찾기
                area = 0;
            }
        }
    }

    printf("%d\n", cnt);
    printf("%d\n", answer);
}