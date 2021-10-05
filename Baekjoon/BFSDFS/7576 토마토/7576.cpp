#include <iostream>
#include <queue>
using namespace std;

int n, m;
int day[1001][1001];
int arr[1001][1001];
int dx[] = { 0, -1, 0, 1};
int dy[] = { -1, 0, 1, 0};
queue<pair<int, int>> q;

void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { // 상하좌우 체크
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] == 0 && day[nx][ny] == -1) {
                    day[nx][ny] = day[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            day[i][j] = -1;

            if (arr[i][j] == 1) {
                q.push(make_pair(i, j)); // 1인 좌표 전부 q에 push
                day[i][j] = 0; // 1은 0일에 해당되므로 0으로 초기화
            }
        }
    }

    BFS();

    int result = 0;
    for (int i = 0; i < n; i++) { // 날짜의 최댓값 
        for (int j = 0; j < m; j++) {
            if (result < day[i][j]) result = day[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // 방문해야 하는 노드 중에 0이 있는지 확인
            if (arr[i][j] == 0 && day[i][j] == -1) result = -1;
        }
    }

    cout << result << endl;
}