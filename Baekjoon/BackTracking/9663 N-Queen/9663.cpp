#include <iostream>
using namespace std;

int n, cnt = 0;
int board[15];

bool check(int row) {
    for (int i = 0; i < row; i++) {
        // 다른 퀸들과 같은 열이나 대각선에 위치 했을 때 false
        if (board[row] == board[i] || row - i == abs(board[row] - board[i])) return false;
    }
    return true;
}

void nqueen(int row) {
    if (row == n) { cnt++; return; }

    for (int i = 0; i < n; i++) {
        board[row] = i;
        if (check(row)) nqueen(row+1); // 현재 행과 열의 위치가 퀸이 있을 수 있는지 체크하고 다음 위치에 퀸을 놓아본다.
    }
}

int main() {
    cin >> n;
    nqueen(0); // 0번 행부터 시작
    cout << cnt << endl;
}