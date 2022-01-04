#include <cstdio>
#include <vector>
using namespace std;

int n, m, answer = 0;
vector<vector<int>> arr(2001, vector<int>());
bool visited[2001];

void dfs(int node, int cnt) {
    visited[node] = true;

    if (cnt >= 5) { answer = 1; return; } // 깊이가 5일 때 answer를 1로 설정

    for (int i = 0; i < arr[node].size(); i++) {
        if (!visited[arr[node][i]]) dfs(arr[node][i], cnt + 1);
    }

    visited[node] = false; // 다음 노드에서 체크하기 위해 visited를 false로 초기화
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (answer == 1) break;
        else dfs(i, 1);
    }

    printf("%d\n", answer);
}