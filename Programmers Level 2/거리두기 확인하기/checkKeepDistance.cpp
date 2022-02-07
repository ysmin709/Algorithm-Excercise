#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visited[5][5];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool bfs(int x, int y, vector<string> places) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if (visited[x][y] >= 4) return true; // 맨해튼 거리 2이하에 사람이 없으면
        
        for (int i = 0; i < 4; i++) { // 4방향 체크
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                if (!visited[nx][ny] && places[nx][ny] == 'O') {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[x][y] + 1;
                }
                else if (!visited[nx][ny] && places[nx][ny] == 'P' && visited[x][y] < 3) return false; // 맨해튼 거리가 2이하면 false 리턴
            }
        }        
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < places.size(); i++) {
        bool check = true;
        
        memset(visited, false, sizeof(visited));
        
        for (int j = 0; j < places[i].size(); j++) {
            for (int k = 0; k < places[i][j].size(); k++) {
                if (places[i][j][k] == 'P') {
                    if (!bfs(j, k, places[i])) {
                        check = false;
                        break;
                    }
                }
            }
            if (!check) break;
        }
        
        if (!check) answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}