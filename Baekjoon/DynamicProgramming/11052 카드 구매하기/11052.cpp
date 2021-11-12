#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n+1, 0);
    vector<int> dp(vec.begin(), vec.end());

    for (int i = 1; i <= n; i++) cin >> vec[i];

    dp[1] = vec[1];

    for (int i = 2; i <= n; i++) {
        // i장의 카드를 구하는 방법 중 가장 큰 값을 적용하여 N까지 구한다.
        for (int j = 1; j <= i; j++) dp[i] = max(dp[i], dp[i-j] + vec[j]);
    }

    cout << dp[n] << endl;
}