#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, answer = 0;
vector<vector<int>> arr(8, vector<int>(8, 0));
vector<vector<int>> vec;
vector<pair<int, int>> virus;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

int BFS() {
    int res = 0;
    for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { // 4방향 체크
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!vec[nx][ny]) {
                    vec[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vec[i][j]) res++;
        }
    }

    return res;
}

void Build_Wall(int cnt) {
    if (cnt == 3) { // 벽 3개를 세우고 BFS
        vec.assign(arr.begin(), arr.end());
        answer = max(BFS(), answer);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j]) {
                arr[i][j] = 1;
                if (cnt < 3) Build_Wall(cnt+1);
                arr[i][j] = 0; // 사용 후 초기화
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2) virus.push_back(make_pair(i, j)); // 바이러스 위치 정보 저장
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j]) {
                arr[i][j] = 1;
                Build_Wall(1);
                arr[i][j] = 0; // 사용 후 초기화
                }
        }
    }
    
    printf("%d\n", answer);
}