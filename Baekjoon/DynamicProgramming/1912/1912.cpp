#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp;
    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    vector<int> dp(vec.size(), 0);
    dp[0] = vec[0]; // 초기값 설정

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + vec[i], vec[i]); // 연속된 값들의 합과 현재 값을 비교하여 큰 값을 dp에 넣는다.
    }

    int big = -1001; // -1000이 제일 작은 수이기 때문에 -1001로 설정
    for (int i = 0; i < n; i++) {
        if (dp[i] > big) big = dp[i];
    }

    cout << big << endl;
}