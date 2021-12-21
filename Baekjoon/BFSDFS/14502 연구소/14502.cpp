#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>> arr(8, vector<int>(8, 0));
vector<vector<int>> vec;
bool visited[8][8];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

void BFS(pair<int, int> node) {
    q.push(node);
    visited[node.first][node.second] = true;

    while(!q.empty()) {
        node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!vec[nx][ny] && !visited[nx][ny]) {
                    vec[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    int answer = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }

    bool check = true;
    int num = 0;
    while(check) {
        vec.assign(arr.begin(), arr.end());
        memset(visited, 0, sizeof(visited));

        int cnt = 0;
        for (int i = (num - 1) / n; i < n; i++) {
            for (int j = (num + 1) % m; j < m; j++) {
                if (!vec[i][j]) { vec[i][j] = 1; cnt++; }
                if (i == n - 1 && j == m - 1) check = false;
                if (cnt == 3)  break;
            }
            if (cnt == 3) { num++; break; }
        }
        cout << num << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // if (cnt == 3) {
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; j < m; j++) {
        //             if (vec[i][j] == 2 && !visited[i][j]) BFS(make_pair(i, j));
        //         }
        //     }

        //     int temp = 0;
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; j < m; j++) {
        //             cout << vec[i][j] << " ";
        //             if (!vec[i][j]) temp++;
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;

        //     if (temp > answer) answer = temp;
        // }
    }

    cout << answer << endl;
}