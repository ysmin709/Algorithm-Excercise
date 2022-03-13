#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr(19, vector<int>(19));

bool check(int x, int y, int color) {
    int cnt = 0, i = 1;

    // 우측 상단 대각선 검사
    while (x - i >= 0 && y + i <= 18 && arr[x - i][y + i] == color) { cnt++; i++; }
    if (cnt == 4) {
        if (x == 18 || y == 0) return true;
        else {
            if (arr[x + 1][y - 1] == color) { cnt = 0; i = 1; }
            else return true;
        }
    }
    else { cnt = 0; i = 1; }

    // 우측 가로 검사
    while (y + i <= 18 && arr[x][y + i] == color) { cnt++; i++; }
    if (cnt == 4) {
        if (y == 0) return true;
        else {
            if (arr[x][y - 1] == color) { cnt = 0; i = 0; }
            else return true;
        }
    }

    // 우측 하단 대각선 검사
    while (x + i <= 18 && y + i <= 18 && arr[x + i][y + i] == color) { cnt++; i++; }
    if (cnt == 4) {
        if (x == 0 || y == 0) return true;
        else {
            if (arr[x - 1][y - 1] == color) { cnt = 0; i = 1; }
            else return true;
        }
    }
    else { cnt = 0; i = 1; }

    // 세로 하단 검사
    while (x + i <= 18 && arr[x + i][y] == color) { cnt++; i++; }
    if (cnt == 4) {
        if (x == 0) return true;
        else {
            if (arr[x - 1][y] == color) { cnt = 0; i = 0; }
            else return true;
        }
    }    

    return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) cin >> arr[i][j];
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (arr[i][j]) {
                if (check(i, j, arr[i][j])) {
                    cout << arr[i][j] << "\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";
}