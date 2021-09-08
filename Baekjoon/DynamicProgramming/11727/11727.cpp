#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n, 1);
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 5;

    for (int i = 3; i < n; i++) dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;

    cout << dp[n-1] << endl;
}