#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
bool adj[1001][1001]; // 인접 행렬
bool visited[1001][1001];
vector<bool> vec(1001, false); // isolated connected component 확인 벡터
queue<int> q;

void BFS(int node) {
    q.push(node);
    vec[node] = true;

    while(!q.empty()) {
        node = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[node][i]) { // 해당 노드와 인접한 노드 확인
                q.push(i);
                vec[i] = true;
                visited[node][i] = true; // 무방향이기 때문에 양쪽으로 체크
                visited[i][node] = true;
            }
        }
    }
}

int main() {
    int answer = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = true; // 무방향 그래프이기 때문에 양쪽으로 체크
        adj[y][x] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] && !visited[i][j]) { BFS(i); answer++; }
        }
    }

    for (int i = 1; i <= n; i++) { // vec[i]가 false면 isolated인 노드이기 때문에 answer를 증가시킨다.
        if (!vec[i]) answer++;
    }

    cout << answer << endl;
}