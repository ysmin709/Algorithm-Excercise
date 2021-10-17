#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, idx, Max = 0;
int arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
vector<int> vec; // 안전 구역의 개수 체크
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void BFS(pair<int, int> node) {
    q.push(node);
    visited[node.first][node.second] = true;
    int cnt = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { // 상하좌우 체크
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (arr[nx][ny] > idx && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    int cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            Max = max(arr[i][j], Max);
        }
    }

    for (idx = 0; idx <= Max; idx++) {
        memset(visited, false, sizeof(visited)); // visited 배열 초기화
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (arr[j][k] > idx && !visited[j][k]) {
                    BFS(make_pair(j, k));
                    cnt++;
                }
            }
        }
        vec.push_back(cnt);
        cnt = 0;
    }

    sort(vec.rbegin(), vec.rend()); // 내림차순 정렬
    cout << vec[0] << endl; // 가장 큰 값 출력
}