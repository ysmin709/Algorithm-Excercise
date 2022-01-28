#include <string>
#include <vector>
using namespace std;

vector<vector<int>> arr(200, vector<int>());
bool visited[200];

void dfs(int node) {
    visited[node] = true;
    
    for (int i = 0; i < arr[node].size(); i++) {
        if (!visited[arr[node][i]]) dfs(arr[node][i]); // 해당 노드와 연결된 노드로 이동
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (i != j && computers[i][j]) arr[i].push_back(j); // 자신과도 연결되어 있으므로 i != j로 자신과의 연결은 생략한다.
        }
    }
    
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}