#include <cstdio>
#include <cstring>
using namespace std;

int answer;
int arr[100001]; // 정보 저장 배열
int visited[100001]; // 방문 순서 저장 배열
bool finish[100001]; // 노드에 대한 dfs가 끝났는지 체크하는 배열

void dfs(int x, int cnt) {
    visited[x] = cnt;

    // 다음 노드가 방문하지 않은 노드라면 탐색한다.
    if (!visited[arr[x]]) dfs(arr[x], cnt + 1);

    // 현재 노드의 방문 순서 - 사이클이 되는 노드의 방문 순서를 하면 1이 줄어들기 때문에
    // 1을 더해준다.
    else if (!finish[arr[x]]) answer -= cnt - visited[arr[x]] + 1;

    finish[x] = true; // 현재 노드에 대한 탐색이 끝났으면 finish를 true로 체크
}

int main() {
    int t, n, temp;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        answer = n;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &temp);
            arr[j] = temp;
        }

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) dfs(j, 1);
        }

        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        memset(finish, false, sizeof(finish));
        printf("%d\n", answer);
    }

}