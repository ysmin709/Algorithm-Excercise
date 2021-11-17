#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, t;
bool arr[100][100];
bool visited[100][100];
vector<int> vec;
queue<pair<int, int>> q;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void BFS(pair<int, int> node) {
    int size = 0;
    q.push(node);
    visited[node.first][node.second] = true;

    while(!q.empty()) {
        size++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { // 상하좌우 체크
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!arr[nx][ny] && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
    vec.push_back(size); // 해당 영역의 넓이를 vec에 추가
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < t; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int j = n - ly - 1; j >= n - ry; j--) { // 현실 좌표를 기준으로 범위를 정한다.
            for (int k = lx; k < rx; k++) arr[j][k] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j] && !visited[i][j]) BFS(make_pair(i, j));
        }
    }

    sort(vec.begin(), vec.end()); // 영역의 넓이 오름차순 정렬
    
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}