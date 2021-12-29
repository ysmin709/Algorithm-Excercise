#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
vector<int> adj[100001];
bool visited[100001];
map<int, int> m;

void dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] && !visited[adj[node][i]]) {
            m[adj[node][i]] = node; // map에 부모노드 체크
            dfs(adj[node][i]); // dfs를 통해 다음 노드로 이동
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b); // 양방향 체크
        adj[b].push_back(a);
    }

    dfs(1); // 루트는 1이므로 시작 정점을 1로 설정

    vector<pair<int, int>> vec(m.begin(), m.end()); // map 정보를 벡터로 받기
    sort(vec.begin(), vec.end()); // key 기준 정렬

    for (int i = 0; i < vec.size(); i++) printf("%d\n", vec[i].second);
}