#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m, n;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int arr[51][51];
bool visited[51][51];
queue<pair<int, int>> q;

void bfs(pair<int, int> node) {
    q.push(node);
    visited[node.first][node.second] = true;

    while(!q.empty()) {
        node = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) { // 8방향 체크
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    while(true) {
        int answer = 0;
        memset(arr, 0, sizeof(arr)); // 입력마다 arr와 visited 배열 초기화
        memset(visited, false, sizeof(visited));

        cin >> m >> n;
        if (m == 0 && n == 0) return 0; // 입력이 0 0이면 프로그램 종료

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] && !visited[i][j]) { bfs(make_pair(i, j)); answer++; } // 섬의 개수 체크
            }
        }
        cout << answer << endl;
    }
}