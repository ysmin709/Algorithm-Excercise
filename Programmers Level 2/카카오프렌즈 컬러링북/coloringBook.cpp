#include <vector>
#include <queue>
using namespace std;

int BFS(pair<int, int> node, int n, int m, vector<vector<int>> &picture, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, -1, 0, 1 };
    
    q.push(node);
    visited[node.first][node.second] = true;
    int cnt = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) { // 상하좌우 체크
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < picture.size() && ny >= 0 && ny < picture[0].size()) {
                if (picture[nx][ny] == picture[x][y] && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        cnt++;
    }
    return cnt; // 해당 영역의 넓이를 리턴
} 


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2, 0);
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int cnt = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 가장 넓은 영역을 answer[1]로 설정
            if (picture[i][j] != 0 && !visited[i][j]) { answer[1] = max(BFS(make_pair(i, j), n, m, picture, visited), answer[1]); cnt++; }
        }
    }
    
    answer[0] = cnt; // 영역의 개수
    
    return answer;
}