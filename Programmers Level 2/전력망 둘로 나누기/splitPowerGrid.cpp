#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool arr[101][101];
bool visited[101];

int bfs(int node, int n) {
    int cnt = 0;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()) {
        node = q.front();
        q.pop();
        cnt++;
        
        for (int i = 1; i <= n; i++) { // 해당 노드와 연결 된 노드 찾기
            if (arr[node][i] && !visited[i]) { // 연결 노드가 방문하지 않은 상태라면
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000000;
    
    for (int i = 0; i < wires.size(); i++) { 
        arr[wires[i][0]][wires[i][1]] = true; // 간선 정보 저장
        arr[wires[i][1]][wires[i][0]] = true;
    }
    
    for (int i = 0; i < wires.size(); i++) {
        memset(visited, false, sizeof(visited));
        
        arr[wires[i][0]][wires[i][1]] = false; // 연결 끊기
        arr[wires[i][1]][wires[i][0]] = false;
        
        int group1 = bfs(wires[i][0], n);
        int group2 = bfs(wires[i][1], n);
        
        answer = min(answer, abs(group1 - group2));
         
        arr[wires[i][0]][wires[i][1]] = true; // 다시 연결
        arr[wires[i][1]][wires[i][0]] = true;       
    }
    
    return answer;
}