#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
char arr[51][51];
bool visited[51][51];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };
queue<pair<int, int>> check_q;
queue<pair<int, pair<int, int>>> q;
vector<int> vec;

void BFS(pair<int, int> node) {
    q.push(make_pair(0, check_q.front()));
    visited[node.first][node.second] = true;

    int max = 0;

    while(!q.empty()) {
        int x = q.front().second.second;
        int y = q.front().second.first;
        int cnt = q.front().first;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (arr[ny][nx] == 'L' && !visited[ny][nx]) {
                    q.push(make_pair(cnt + 1, make_pair(ny, nx)));
                    visited[ny][nx] = true;
                    if (max < cnt + 1) max = cnt + 1;
                }
            }
        }
    }
    vec.push_back(max);
}

int main() {
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < w; j++) {
            arr[i][j] = temp[j];
            if (arr[i][j] == 'L') check_q.push(make_pair(i, j));
        }
    }

    while(!check_q.empty()) {
        memset(visited, false, sizeof(visited));
        BFS(check_q.front());
        check_q.pop();
    }

    sort(vec.rbegin(), vec.rend());

    cout << vec[0] << endl;
}