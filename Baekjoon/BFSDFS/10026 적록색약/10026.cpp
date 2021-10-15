#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
char arr[101][101];
bool visited[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

void BFS(char ch, pair<int, int> node) { // 일반인 BFS
    q.push(node);
    visited[node.first][node.second] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { // 상하좌우 체크
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (arr[nx][ny] == ch && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

void BFS_weak(char ch, pair<int, int> node) { // 적록색약 BFS
    q.push(node);
    visited[node.first][node.second] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { // 상하좌우 체크
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (ch == 'R') { // BFS_weak에 인자를 넘길 때 R이나 G면 R로 넘기도록 했음
                    if ((arr[nx][ny] == 'R' || arr[nx][ny] == 'G') && !visited[nx][ny]) {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
                else if (ch == 'B') {
                    if (arr[nx][ny] == ch && !visited[nx][ny]) {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }                    
                }
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }

    int answer = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'R' && !visited[i][j]) { BFS('R', make_pair(i, j)); answer++; }
            else if (arr[i][j] == 'G' && !visited[i][j]) { BFS('G', make_pair(i, j)); answer++; }
            else if (arr[i][j] == 'B' && !visited[i][j]) { BFS('B', make_pair(i, j)); answer++; }
        }
    }
    cout << answer << " ";

    answer = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((arr[i][j] == 'R' || arr[i][j] == 'G') && !visited[i][j]) { BFS_weak('R', make_pair(i, j)); answer++; }
            else if (arr[i][j] == 'B' && !visited[i][j]) { BFS_weak('B', make_pair(i, j)); answer++; }
        }
    }
    cout << answer << endl;
}