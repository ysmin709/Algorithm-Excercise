#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, answer, cnt;
vector<vector<int>> arr(10001, vector<int>());
bool visited[10001];
vector<pair<int, int>> check;

void dfs(int node) {
    visited[node] = true;
    cnt++;

    for (int i = 0; i < arr[node].size(); i++) {
        if (!visited[arr[node][i]]) dfs(arr[node][i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cnt = 0;
        dfs(i);
        check.push_back(make_pair(cnt, i)); // 해킹할 수 있는 수를 기준으로 sort하기 위해 cnt를 key값으로 설정
        memset(visited, false, sizeof(visited));
    }
    
    sort(check.rbegin(), check.rend()); // pair의 key값 기준으로 내림차순 sort

    vector<int> vec; // 같은 수의 컴퓨터를 해킹할 수 있을 때, 번호 순서대로 출력하기 위한 벡터
    int max = check[0].first;
    for (int i = 0; i < n; i++) {
        if (check[i].first == max) vec.push_back(check[i].second);
    }

    sort(vec.begin(), vec.end()); // 번호 순으로 오름차순 정렬

    for (int i = 0; i < vec.size(); i++) printf("%d ", vec[i]);
}