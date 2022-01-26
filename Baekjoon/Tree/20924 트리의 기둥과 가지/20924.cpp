#include <cstdio>
#include <vector>
using namespace std;

int giga, pillar = 0, branch = 0;
vector<vector<pair<int, int>>> arr(200001, vector<pair<int, int>>());
bool visited[200001];

void check_pillar(int node) { // 기둥의 길이 체크
    visited[node] = true;

    int cnt = 0;
    for (int i = 0; i < arr[node].size(); i++) { 
        if (!visited[arr[node][i].first]) cnt++; // 자식 노드의 개수 체크
    }

    if (cnt <= 1) { // 자식 노드가 1개 이하라면 giga 노드가 아니므로 기둥 길이 증가
        for (int i = 0; i < arr[node].size(); i++) {
            if (!visited[arr[node][i].first]) {
                pillar += arr[node][i].second;
                check_pillar(arr[node][i].first);
            }
        }
    }
    else { // 자식노드가 2개 이상이면 현재 노드를 giga 노드로 설정
        giga = node;
        return;
    }
}

void check_branch(int node, int cost) {
    visited[node] = true;
    branch = max(branch, cost); // 가지 길이 중 가장 긴 값

    for (int i = 0; i < arr[node].size(); i++) {
        if (!visited[arr[node][i].first]) check_branch(arr[node][i].first, cost + arr[node][i].second);
    }
}

int main() {
    int n, root;
    scanf("%d %d", &n, &root);

    int x, y, cost;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &x, &y, &cost);
        arr[x].push_back(make_pair(y, cost));
        arr[y].push_back(make_pair(x, cost));
    }

    check_pillar(root);
    check_branch(giga, 0);

    printf("%d %d\n", pillar, branch);
}