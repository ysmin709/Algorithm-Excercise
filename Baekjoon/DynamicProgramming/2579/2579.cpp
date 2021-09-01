#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    vector<int> vec;

    for (int i = 0; i < t; i++) {
        cin >> n;
        vec.push_back(n);
    }

    // vec의 크기만큼 dp 설정
    vector<int> dp(t, 0);

    // 초기값 설정
    dp[0] = vec[0]; dp[1] = max(vec[1], vec[0] + vec[1]);
    dp[2] = max(vec[0] + vec[2], vec[1] + vec[2]);

    // 2칸 떨어진 값과 1칸 떨어진 값을 비교
    for (int i = 3; i <= t; i++) dp[i] = max(dp[i-2] + vec[i], dp[i-3] + vec[i] + vec[i-1]);

    cout << dp[t-1] << endl;
}