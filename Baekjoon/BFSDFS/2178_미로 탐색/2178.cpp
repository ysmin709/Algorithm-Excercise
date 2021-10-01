#include <iostream>
#include <string>
#include <queue>
using namespace std;

int r, c;
int visited[102][102];
int arr[102][102];
int answer[102][102];
queue<pair<int, int>> q; // pair로 row와 column 저장

void BFS(int row, int column) {
    q.push(make_pair(row, column)); // 처음 시작 부분 체크
    visited[row][column] = 1;
    answer[row][column] = 1;

    while (!q.empty()) {
        row = q.front().first; // 현재 탐색할 부분 저장
        column = q.front().second;
        if (arr[row][column+1] && !visited[row][column+1]) { // 상하좌우 체크한 후 조건에 해당하면 queue에 push
            q.push(make_pair(row, column+1));
            visited[row][column+1] = 1;
            answer[row][column+1] = answer[row][column] + 1;
        }
        if (arr[row+1][column] && !visited[row+1][column]) {
            q.push(make_pair(row+1, column));
            visited[row+1][column] = 1;
            answer[row+1][column] = answer[row][column] + 1;
        }
        if (arr[row][column-1] && !visited[row][column-1]) {
            q.push(make_pair(row, column-1));
            visited[row][column-1] = 1;
            answer[row][column-1] = answer[row][column] + 1;
        }
        if (arr[row-1][column] && !visited[row-1][column]) {
            q.push(make_pair(row-1, column));
            visited[row-1][column] = 1;
            answer[row-1][column] = answer[row][column] + 1;
        }                
        q.pop(); // 탐색이 끝난 부분은 pop
    }
    cout << answer[r][c] << endl;
}

int main() {
    cin >> r >> c;
    
    for (int i = 1; i <= r; i++) {
        string temp = "";
        cin >> temp;
        for (int j = 1; j <= c; j++) arr[i][j] = temp[j-1] - '0';
    }

    BFS(1, 1);
}