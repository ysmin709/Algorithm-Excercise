#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int n, m, cnt = 0;
char arr[101][101];
bool visited[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y) {
    visited[x][y] = true;
    char check = arr[x][y]; // 아군인지 적군인지 체크
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (arr[nx][ny] == check && !visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        char temp[101];
        scanf("%s", temp);
        for (int j = 0; j < n; j++) arr[i][j] = temp[j];
    }

    int friendly = 0, enemy = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'W' && !visited[i][j]) { // 아군일 때
                dfs(i, j);
                friendly += pow(cnt, 2); // 아군의 수 ^ 2
                cnt = 0;
            }
            else if (arr[i][j] == 'B' && !visited[i][j]) { // 적군일 때
                dfs(i, j);
                enemy += pow(cnt, 2); // 적군의 수 ^ 2
                cnt = 0;
            }
        }
    }    

    printf("%d %d\n", friendly, enemy);
}