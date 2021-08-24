#include <iostream>
#include <algorithm>

using namespace std;

int DP[1000001];

int main() {
    int n;
    cin >> n;

    DP[1] = 0;
    int cnt = 0;
    for (int i = 2; i <= n; i++) { // bottom-up 방식 사용
        DP[i] = DP[i-1] + 1;
        if (i % 2 == 0) DP[i] = min(DP[i], DP[i/2] + 1);
        if (i % 3 == 0) DP[i] = min(DP[i], DP[i/3] + 1);
    }
    cout << DP[n] << endl;
}