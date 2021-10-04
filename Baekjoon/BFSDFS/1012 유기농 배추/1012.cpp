#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[1002][1002];
int visited[1002][1002];
queue<pair<int, int>> q;

void BFS(pair<int, int> node) {
    q.push(node); // 시작 노드 설정
    visited[q.front().first][q.front().second];

    while(!q.empty()) {
        node = q.front();
        if (arr[node.first+1][node.second] && !visited[node.first+1][node.second]) { // 상하좌우 체크
            q.push(make_pair(node.first+1, node.second));
            visited[node.first+1][node.second] = 1;
        }
        if (arr[node.first-1][node.second] && !visited[node.first-1][node.second]) {
            q.push(make_pair(node.first-1, node.second));
            visited[node.first-1][node.second] = 1;
        }
        if (arr[node.first][node.second+1] && !visited[node.first][node.second+1]) {
            q.push(make_pair(node.first, node.second+1));
            visited[node.first][node.second+1] = 1;
        }
        if (arr[node.first][node.second-1] && !visited[node.first][node.second-1]) {
            q.push(make_pair(node.first, node.second-1));
            visited[node.first][node.second-1] = 1;
        }
        q.pop();
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        memset(arr, 0, sizeof(arr)); // arr와 visited 배열 0으로 초기화
        memset(visited, 0, sizeof(visited));
        int n, m, k, answer = 0;
        cin >> n >> m >> k;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            arr[x+1][y+1] = 1; // 상하좌우 체크할 때 인덱스 문제 해결하기 위해서 +1을 해준다
        }

        for (int j = 1; j <= n; j++) { // 완전탐색하면서 체크
            for (int h = 1; h <= m; h++) {
                if (arr[j][h] && !visited[j][h]) {
                    BFS(make_pair(j, h));
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }
}