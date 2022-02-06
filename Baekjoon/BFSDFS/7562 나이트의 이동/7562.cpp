#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int visited[300][300];
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
queue<pair<int, int>> q;
int n;

void bfs(pair<int, int> start, pair<int, int> target) {
    visited[start.first][start.second] = 1;
    q.push(start);

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) { // 움직일 수 있는 8가지 방법
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[x][y] + 1; // visited에 거리 표시
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        for (int j = 0; j < n; j++) memset(visited[j], 0, sizeof(visited[j]));

        int x, y;
        pair<int, int> start, target;
        scanf("%d %d", &x, &y);
        start = make_pair(x, y);
        scanf("%d %d", &x, &y);
        target = make_pair(x, y);

        bfs(start, target);

        printf("%d\n", visited[target.first][target.second] - 1); // bfs 시작 부분에 방문 표시를 1로 하므로 -1을 해줘야 한다.
    }
}