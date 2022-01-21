#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> arr(20001, vector<int>());
int visited[20001];

void dfs(int node) {
    if (!visited[node]) visited[node] = 1; // 처음 방문한 노드는 1로 설정

    for (int i = 0; i < arr[node].size(); i++) {
        if (!visited[arr[node][i]]) {
            if (visited[node] == 1) visited[arr[node][i]] = 2; // 현재 노드가 1이라면 인접 노드는 2로 설정
            else if (visited[node] == 2) visited[arr[node][i]] = 1; // 현재 노드가 2라면 인접 노드는 1로 설정
            dfs(arr[node][i]);
        }
    }
}

bool checkBipartiteGraph(int v) { // 이분 그래프인지 체크
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (visited[i] == visited[arr[i][j]]) return false;
        }
    }
    return true;
}

int main() {
    int t, v, e;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &v, &e);
        for (int j = 0; j < e; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x].push_back(y);
            arr[y].push_back(x);
        }

        for (int i = 1; i <= v; i++) dfs(i);

        if (checkBipartiteGraph(v)) printf("YES\n");
        else printf("NO\n");

        memset(visited, 0, sizeof(visited));
        for (int j = 0; j <= v; j++) arr[j].clear();
    }
}