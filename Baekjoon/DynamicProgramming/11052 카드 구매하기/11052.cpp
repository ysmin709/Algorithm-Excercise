#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n+1, 0);
    vector<int> dp(vec.begin(), vec.end());

    for (int i = 1; i <= n; i++) cin >> vec[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) dp[i] = max(dp[i], dp[i] + vec[i]);
    }

    cout << dp[n] << endl;
}