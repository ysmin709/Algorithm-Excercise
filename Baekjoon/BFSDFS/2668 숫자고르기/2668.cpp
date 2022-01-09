#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int arr[101];
int visited[101];
vector<int> vec;

void dfs(int x, int cnt) {
    if (!visited[cnt]) { // 방문하지 않았다면
        visited[cnt] = x;
        dfs(x, arr[cnt]);
    }
    else if (x == cnt) { // 방문 했던 노드라면 (사이클 인식)
        vec.push_back(x);
        return;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); i++) printf("%d\n", vec[i]);
}