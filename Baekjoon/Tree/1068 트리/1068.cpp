#include <cstdio>
#include <vector>
using namespace std;

int del, answer = 0;
vector<vector<int>> arr(50, vector<int>());
bool visited[50];

void dfs(int node) {
    visited[node] = true;

    if (arr[node].size() == 0) answer++; // 리프 노드이면 answer 증가
    else {
        for (int i = 0; i < arr[node].size(); i++) {
            if (!visited[arr[node][i]]) dfs(arr[node][i]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> root;

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        
        if (temp == -1) root.push_back(i); // -1의 개수만큼 트리가 있으므로 각 트리의 root 노드 체크
        else arr[temp].push_back(i);
    }

    scanf("%d", &del);

    for (int i = 0; i < n; i++) { // 삭제할 노드 전부 삭제
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == del) arr[i].erase(arr[i].begin()+j);
        }
    }

    for (int i = 0; i < root.size(); i++) { // 여러 개가 있을 수 있는 트리의 root에서 dfs 시작
        if (root[i] != del) dfs(root[i]);
    }

    printf("%d", answer);
}