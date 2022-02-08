#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> arr(51, vector<pair<int, int>>(51, make_pair(0, 0)));
int visited[51];
queue<int> q;

void bfs(int node, int K) {
    visited[node] = 1; // 1번 노드 방문
    q.push(node);
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        
        for (int i = 0; i < arr[node].size(); i++) {
            if (!visited[arr[node][i].first] || visited[arr[node][i].first] > visited[node] + arr[node][i].second) { // 해당 노드를 방문하지 않았거나 거리가 더 짧은 방법을 찾았다면
                q.push(arr[node][i].first);
                visited[arr[node][i].first] = visited[node] + arr[node][i].second;                
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for (int i = 0; i < road.size(); i++) {
        arr[road[i][0]].push_back(make_pair(road[i][1], road[i][2])); // 양방향 연결
        arr[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    bfs(1, K);
    
    for (int i = 1; i <= N; i++) {
        if (visited[i] <= K + 1) answer++; // visited 체크를 위해 1번 노드의 거리를 1로 설정 했으므로 K에 1을 더한 값으로 비교한다.
    }

    return answer;
}