#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        vector<long long> dp(101, 1);
        dp[4] = 2; // index 5까지는 중복 되므로 초기화한다.
        dp[5] = 2;

        for (int j = 6; j <= n; j++) dp[j] = dp[j-1] + dp[j-5];

        cout << dp[n] << endl;
    }
}