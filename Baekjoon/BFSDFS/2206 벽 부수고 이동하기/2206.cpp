#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1000][1000];
int answer[1000][1000][2]; // 벽을 부쉈는지 체크하기 위해 3차원
queue<pair<pair<int, int>, int>> q;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int BFS() {
    q.push(make_pair(make_pair(0, 0), 1));
    answer[0][0][1] = 1;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int check = q.front().second; // 벽을 부쉈는지 체크
        q.pop();

        if (x == n-1 && y == m-1) return answer[x][y][check];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] && check) { // 벽을 만났을 때 벽을 부수지 않았다면
                    q.push(make_pair(make_pair(nx, ny), 0));
                    answer[nx][ny][check-1] = answer[x][y][check] + 1;
                }
                else if (!arr[nx][ny] && !answer[nx][ny][check]) { // 벽이 아닌데 방문하지 않았다면
                    q.push(make_pair(make_pair(nx, ny), check));
                    answer[nx][ny][check] = answer[x][y][check] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string temp = "";
        cin >> temp;
        for (int j = 0; j < m; j++) arr[i][j] = temp[j] - '0';
    }

    cout << BFS() << endl;
}