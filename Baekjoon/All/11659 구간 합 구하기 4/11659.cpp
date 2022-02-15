#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, m, temp, x, y;
    cin >> n >> m;

    vector<int> vec(n+1, 0);
    for (int i = 0; i < n; i++) { // 입력 받으면서 구간 합 저장
        cin >> temp;
        vec[i+1] = vec[i] + temp;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << vec[y] - vec[x-1] << "\n";
    }
}