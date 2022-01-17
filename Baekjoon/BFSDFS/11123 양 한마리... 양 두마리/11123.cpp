#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
string arr[101];
bool visited[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) { // 4방향 체크
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (arr[nx][ny] == '#' && !visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) cin >> arr[j]; // string으로 1줄씩 받기
        
        int answer = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[j][k] == '#' && !visited[j][k]) {
                    dfs(j, k);
                    answer++;
                }
            }
        }
        cout << answer << endl;

        for (int i = 0; i < n; i++) memset(visited[i], false, sizeof(visited[i])); // 다음 케이스를 위해 visited배열 초기화
    }
}