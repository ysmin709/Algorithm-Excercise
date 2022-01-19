#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int answer = 0, max_node = 0;
vector<vector<pair<int, int>>> arr(100001, vector<pair<int, int>>());
bool visited[100001];

void dfs(int node, int cost) {
    visited[node] = true;
    if (answer < cost) {
        answer = cost;
        max_node = node;
    }

    for (int i = 0; i < arr[node].size(); i++) {
        if (!visited[arr[node][i].first]) dfs(arr[node][i].first, cost + arr[node][i].second);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int node, target = 0, cost;
        scanf("%d", &node);

        while (true) {
            scanf("%d", &target);
            if (target == -1) break;
            scanf("%d", &cost);
            arr[node].push_back(make_pair(target, cost));
            arr[target].push_back(make_pair(node, cost));
        }
    }

    dfs(1, 0); // 임의의 노드 설정 후 해당 노드의 가장 먼 거리 구하기
    memset(visited, false, sizeof(visited));
    dfs(max_node, 0); // 가장 먼 거리의 노드에서 다시 가장 먼 거리의 노드 구하기

    printf("%d\n", answer);
}