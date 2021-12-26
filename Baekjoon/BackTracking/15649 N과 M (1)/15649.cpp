#include <cstdio>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int k) {
    if (k == m) { // k == m이면 arr의 값 m개 출력
        for (int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");
    }
    else { // 목표 위치에 도달하지 않았으면
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                arr[k] = i; // arr에 i 저장
                visited[i] = true;
                dfs(k + 1); // 목표 위치까지 이동
                visited[i] = false; // 백트래킹
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    dfs(0);
}