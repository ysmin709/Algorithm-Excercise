#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, start;
vector<vector<pair<int, int>>> arr(20001, vector<pair<int, int>>());
vector<int> dist(20001, 10000000);

void dijkstra(int node) {
    priority_queue<pair<int, int>> pq; // 우선순위 큐 사용
    pq.push(make_pair(0, node));
    dist[node] = 0;

    while (!pq.empty()) {
        node = pq.top().second;
        int cost = -pq.top().first; // 가장 작은게 앞으로 오므로 음수로 설정
        pq.pop();

        for (int i = 0; i < arr[node].size(); i++) {
            int next_node = arr[node][i].first;
            int next_cost = cost + arr[node][i].second;

            if (dist[next_node] > next_cost) { // 이전 dist 값이 현재 거리보다 크다면
                dist[next_node] = next_cost;
                pq.push(make_pair(-next_cost, next_node));
            }
        }
    }
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    cin >> v >> e >> start;

    int x, y, cost;
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> cost;
        arr[x].push_back(make_pair(y, cost));
    }

    dijkstra(start);

    for (int i = 1; i <= v; i++) {
        if (dist[i] == 10000000) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
} 