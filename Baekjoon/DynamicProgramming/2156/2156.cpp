#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp;
    cin >> n;

    vector<int> vec(n+1, 0);
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++) cin >> vec[i];

    dp[1] = vec[1]; // dp 초기값 설정
    dp[2] = dp[1] + vec[2];

    for (int i = 3; i <= n; i++) { // 3개가 연속되지 않아야 하므로 3개 값을 비교
        dp[i] = max(dp[i-1], max(dp[i-2] + vec[i],  dp[i-3] + vec[i-1] + vec[i]));
    }

    cout << dp[n] << endl;
}
