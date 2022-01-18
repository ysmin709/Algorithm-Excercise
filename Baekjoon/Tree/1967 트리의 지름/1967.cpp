#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int answer = 0;
vector<vector<pair<int, int>>> arr(10001, vector<pair<int, int>>());
bool visited[10001];

void dfs(int node, int cost) {
    visited[node] = true;
    answer = max(answer, cost); // 지름 최대값 찾기

    for (int i = 0; i < arr[node].size(); i++) { // 해당 노드에 연결된 노드 수만큼 반복
        if (!visited[arr[node][i].first]) dfs(arr[node][i].first, cost + arr[node][i].second);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++){
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);
        arr[x].push_back(make_pair(y, cost)); // 방향이 없으므로 양쪽으로 연결
        arr[y].push_back(make_pair(x, cost));
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
        memset(visited, false, sizeof(visited));
    }

    printf("%d\n", answer);
}