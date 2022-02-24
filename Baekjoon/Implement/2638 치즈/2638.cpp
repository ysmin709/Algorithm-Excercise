#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
bool check = true;
int arr[100][100];
bool visited[100][100];
int contact[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> res;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!arr[nx][ny] && !visited[nx][ny]) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
				else if (arr[nx][ny]) {
					contact[nx][ny]++;
					if (contact[nx][ny] == 2) res.push(make_pair(nx, ny)); // 녹는 것이 확정된 부분을 res에 push
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int answer = 0;

    cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	while (true) {
		memset(visited, false, sizeof(visited));
		memset(contact, 0, sizeof(contact));

		bfs(0, 0); // 외부 공기의 시작 부분

		if (res.empty()) break; // 치즈가 모두 녹았을 때

		answer++;

		while(!res.empty()) {
			arr[res.front().first][res.front().second] = 0;
			res.pop();
		}
	}
	
	cout << answer << "\n";
}