#include <cstdio>
#include <vector>
using namespace std;

int n, m, answer = -1;
int a, b; // a : 시작 정점, b : 목표 정점
vector<vector<int>> arr(101, vector<int>());
bool visited[101];

void dfs(int node, int cnt) { // 거리를 체크하기 위해 cnt를 dfs의 인자로 설정
    visited[node] = true;

    for (int i = 0; i < arr[node].size(); i++) {
        if (node == b) { // 목표 정점에 도달했다면
            answer = cnt;
            break;
        }
        if (!visited[arr[node][i]]) dfs(arr[node][i], cnt + 1);
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    dfs(a, 0);

    printf("%d\n", answer);
}