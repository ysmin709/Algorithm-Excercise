#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, red, green, blue;
    cin >> t;
    vector<vector<int>> vec(t, vector<int>(3, 0));
    vector<vector<int>> dp(t, vector<int>(3, 0));

    for (int i = 0; i < t; i++) { // rgb 값을 입력받아 vec 구성
        cin >> red >> green >> blue;
        vec[i][0] = red;  vec[i][1] = green; vec[i][2] = blue;
    }

    // dp의 첫 번째 줄은 값을 넣어놓는다.
    dp[0][0] = vec[0][0]; dp[0][1] = vec[0][1]; dp[0][2] = vec[0][2];

    for (int i = 1; i < t; i++) { // dp의 각 위치마다 i-1번째 줄과 i번째 줄의 색이 겹치지 않도록 한다.
        dp[i][0] = min(dp[i-1][1] + vec[i][0], dp[i-1][2] + vec[i][0]);
        dp[i][1] = min(dp[i-1][0] + vec[i][1], dp[i-1][2] + vec[i][1]);
        dp[i][2] = min(dp[i-1][0] + vec[i][2], dp[i-1][1] + vec[i][2]);
    }

    cout << min(dp[dp.size()-1][0], min(dp[dp.size()-1][1], dp[dp.size()-1][2]));
}