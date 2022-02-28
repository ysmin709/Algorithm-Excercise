#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, answer = 0;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) { // 4방향 체크
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int row = 0, col = 0;

                    swap(arr[nx][ny], arr[i][j]);
                    
                    for (int u = i; u >= 0; u--) { // 현재 위치 열 탐색
                        if (arr[i][j] == arr[u][j]) col++;
                        else break;
                    }
                    for (int d = i + 1; d < n; d++) { // 열 탐색
                        if (arr[i][j] == arr[d][j]) col++;
                        else break;
                    }
                    for (int l = j; l >= 0; l--) { // 현재 위치 행 탐색
                        if (arr[i][j] == arr[i][l]) row++;
                        else break;
                    }
                    for (int r = j + 1; r < n; r++) { // 행 탐색
                        if (arr[i][j] == arr[i][r]) row++;
                        else break;
                    }

                    answer = max(answer, max(row, col));
                    swap(arr[nx][ny], arr[i][j]);
                }
            }
        }
    }

    cout << answer << "\n";
}