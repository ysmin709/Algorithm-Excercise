#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[27][27];
int visited[27][27];
queue<pair<int, int>> q;
vector<int> answer;

void BFS(int row, int column) {
    int t = 0; 
    q.push(make_pair(row, column));
    visited[row][column] = 1;

    while (!q.empty()) {
        t++;
        row = q.front().first;
        column = q.front().second;

        if (arr[row][column+1] && !visited[row][column+1]) { // 상하좌우 체크한 후 조건에 해당하면 queue에 push
            q.push(make_pair(row, column+1));
            visited[row][column+1] = 1;
        }
        if (arr[row+1][column] && !visited[row+1][column]) {
            q.push(make_pair(row+1, column));
            visited[row+1][column] = 1;
        }
        if (arr[row][column-1] && !visited[row][column-1]) {
            q.push(make_pair(row, column-1));
            visited[row][column-1] = 1;
        }
        if (arr[row-1][column] && !visited[row-1][column]) {
            q.push(make_pair(row-1, column));
            visited[row-1][column] = 1;
        }
        q.pop();
    }
    answer.push_back(t); // 몇개의 집이 인접해 있는지 체크
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= temp.size(); j++) arr[i][j] = temp[j-1] - '0';
    }

    for (int i = 1; i <= n; i++) { // 전체 탐색을 위한 이중 반복문
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) BFS(i, j);
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}