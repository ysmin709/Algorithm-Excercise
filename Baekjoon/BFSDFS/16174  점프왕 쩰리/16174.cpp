#include <iostream>
using namespace std;

int n;
string answer = "Hing";
int arr[501][501];
bool visited[501][501];
int dx[] = {1, 0};
int dy[] = {0, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    
    if (x == n-1 && y == n-1) { // 목표 지점에 도착
        answer = "HaruHaru";
        return;
    }

    for (int i = 0; i < 2; i++) { // 오른쪽과 밑으로만 진행한다.
        int nx = x + dx[i] * arr[x][y];
        int ny = y + dy[i] * arr[x][y];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }

    dfs(0, 0);
    
    cout << answer << endl;
}