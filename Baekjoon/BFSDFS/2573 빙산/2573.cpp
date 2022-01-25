#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int m, n, answer;
vector<vector<int>> arr(300, vector<int>(300, 0));
vector<vector<int>> temp(300, vector<int>(300, 0));
bool visited[300][300];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void melt(int x, int y) { // 주변의 바다 숫자만큼 빙산을 녹이는 함수
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!arr[nx][ny]) {
                if (temp[x][y] > 0) temp[x][y]--;
            }
            else if (!visited[nx][ny]) melt(nx, ny);
        }
    }
}

void dfs(int x, int y) { // 빙산의 개수를 체크하는 함수
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (arr[nx][ny] && !visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
    }

    copy(arr.begin(), arr.end(), temp.begin());

    int cnt = 0;
    bool check = false;
    while(true) {
        answer++;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] && !visited[i][j]) melt(i, j);
            }
        }

        copy(temp.begin(), temp.end(), arr.begin());
        for (int i = 0; i < m; i++) memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        if (cnt == 0) { answer = 0; break; } // 빙산이 전부 녹았으면
        if (cnt >= 2) break; // 빙산이 2조각 이상으로 나누어 졌으면
        cnt = 0; 

        for (int i = 0; i < m; i++) memset(visited, false, sizeof(visited));
    }

    printf("%d\n", answer);
}