#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m, n, answer = 0;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int arr[50][50];
bool visited[50][50];
queue<pair<int, int>> q;

void bfs(pair<int, int> node) {
    q.push(node);
    visited[node.first][node.second];

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        cout << x << " " << y << endl;
    }
}

int main() {
    while(true) {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));

        cin >> m >> n;
        if (m == 0 && n == 0) return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] && !visited[i][j]) { bfs(make_pair(i, j)); answer++; }
            }
        }
        cout << answer << endl;
    }
}