#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin(n+1, 0);
    vector<int> dp(k+1, 100000); // min을 사용하므로 경우의 수가 불가능한 큰 숫자 설정

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
        for (int j = coin[i]; j <= k; j++) dp[j] = min(dp[j], dp[j - coin[i]] + 1); // 모든 경우의 수 체크
    }

    if (dp[k] == 100000) cout << -1 << endl;
    else cout << dp[k] << endl;
}