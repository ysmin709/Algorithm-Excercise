#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n, 1);

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }

    cout << dp[n-1] << endl;
}