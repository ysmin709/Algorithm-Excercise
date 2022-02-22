#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int r, c;
vector<string> arr;
vector<vector<char>> vec(1001, vector<char>(1001, '#'));
bool visited[1001][1001];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

void bfs(int x, int y) {
    visited[x][y] = true;
    q.push(make_pair(x, y));
    vec[x][y] = '.';

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (!visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
                    q.push(make_pair(nx, ny));
                    vec[nx][ny] = '.';
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    cin >> r >> c;

    string temp;
    for (int i = 0; i < r; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    int hr, hc;
    cin >> hr >> hc >> temp;

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == 'L') hc--;
        else if (temp[i] == 'R') hc++;
        else if (temp[i] == 'U') hr--;
        else if (temp[i] == 'D') hr++;
        else bfs(hr - 1, hc - 1);
    }

    vec[hr - 1][hc - 1] = '.'; // 자신의 위치 체크
    for (int i = 0; i < 4; i++) { // 마지막 자신의 위치의 4방향 체크
        int nx = hr + dx[i] - 1;
        int ny = hc + dy[i] - 1;

        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (vec[nx][ny] == '#') vec[nx][ny] = '.';
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << vec[i][j];
        cout << "\n";
    }
}