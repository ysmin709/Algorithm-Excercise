#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> arr(1001, vector<pair<int, int>>());
bool visited[1001];

void dfs(int start, int end, int cost) {
    visited[start] = true;

    if (start == end) { // 목표 지점에 도착했다면 현재 비용 출력 후 종료
        printf("%d\n", cost);
        return;
    }

    for (int i = 0; i < arr[start].size(); i++) {
        if (!visited[arr[start][i].first]) dfs(arr[start][i].first, end, cost + arr[start][i].second);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int u, v, c;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d %d", &u, &v, &c);
        arr[u].push_back(make_pair(v, c));
        arr[v].push_back(make_pair(u, c));
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        dfs(a, b, 0);
        memset(visited, false, sizeof(visited));
    }
}