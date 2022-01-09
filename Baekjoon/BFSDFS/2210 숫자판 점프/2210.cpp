#include <cstdio>
#include <map>
using namespace std;

int arr[5][5];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
map<int, int> m; // 중복 방지 용도로 map 사용

void dfs(int x, int y, int num, int cnt) {
    if (cnt == 6) {
        m[num] = 1;
        return;
    }

    for (int i = 0; i < 4; i++) { // 4방향 체크
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) dfs(nx, ny, num * 10 + arr[nx][ny], cnt + 1); // 중복 선택 가능이므로 visited는 없음
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) scanf("%d", &arr[i][j]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) dfs(i, j, arr[i][j], 1); // 모든 노드 체크
    }

    printf("%d\n", m.size());

    // vector<pair<int, int>> vec(m.begin(), m.end()); // 결과 테스트

    // for (int i = 0; i < vec.size(); i++) {
    //     printf("%d\n", vec[i].first);
    // }
}