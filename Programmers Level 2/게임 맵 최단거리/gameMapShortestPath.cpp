#include <vector>
#include <queue>
using namespace std;

bool visited[101][101];
queue<pair<int, int>> q;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void BFS(vector<vector<int>> &maps) {
    q.push(make_pair(0, 0)); // 시작점이 무조건 0, 0
    visited[0][0] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) { // 현재 위치에서 상하좌우 체크
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < maps.size() && ny >= 0 && ny < maps[0].size()) {
                if (maps[nx][ny] && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    maps[nx][ny] = maps[x][y] + 1; // 이전 위치보다 거리가 1멀기 때문에 이전 위치 +1로 초기화
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps) {
    int answer = 0;
    
    BFS(maps);
    
    if (maps[maps.size()-1][maps[0].size()-1] == 1) return -1;
    else return maps[maps.size()-1][maps[0].size()-1];
}