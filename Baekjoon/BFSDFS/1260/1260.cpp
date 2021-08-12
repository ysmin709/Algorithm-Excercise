#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001 // 최대 정점의 개수가 1000인데 0은 사용하지 않으므로 1001로 설정

int N, V, S;
int d_visited[MAX] = {0};
int adj[MAX][MAX] = {0};
queue<int> q;

void DFS(int node) {
    cout << node << " ";

    for (int i = 1; i <= N; i++) {
        if (adj[node][i] && !d_visited[i]) {
            d_visited[i] = 1;
            DFS(i);
        }
    }
}

void BFS(int node, int *b_visited) {
    q.push(node); // queue에 현재 값 추가

    while(!q.empty()) { // queue에 값이 없을 때까지
        cout << q.front() << " ";

        node = q.front(); // 체크할 노드를 업데이트
        for (int i = 1; i <= N; i++) { // 간선이 존재하고, 방문하지 않은 노드일 때
            if (adj[node][i] && !b_visited[i]) {
                b_visited[i] = 1; // 방문했다고 표시하고
                q.push(i); // queue에 추가한다.
            }
        }
        q.pop();
    }
}

int main() {
    cin >> N >> V >> S; // 정점 개수, 간선 개수, 시작 정점 입력

    for (int i = 0; i < V; i++) { // 간선 정보를 adj 배열에 저장
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    d_visited[S] = 1; // 시작 정점은 1로 초기화하고 시작
    DFS(S);

    cout << endl;

    int b_visited[MAX] = {0};
    b_visited[S] = 1; // 시작 정점은 1로 초기화하고 시작
    BFS(S, b_visited);
}