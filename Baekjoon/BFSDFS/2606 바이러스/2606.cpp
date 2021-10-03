#include <iostream>
#include <queue>
using namespace std;

int n, c, answer = 0;
int visited[101];
int adj[101][101];
queue<int> q;

void BFS(int node) {
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()) {
        node = q.front();

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
        q.pop();
        answer++;
    }
    cout << answer-1 << endl; // 1번 노드는 제외하기 때문에 -1을 해준다
}

int main() {
    cin >> n >> c;

    int x, y;
    for (int i = 0; i < c; i++) {
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    BFS(1);
}