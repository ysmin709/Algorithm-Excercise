#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp;
    cin >> n;

    vector<int> vec;
    vector<int> dp(n, 1); // 모든 값이 무조건 1 이상이기 때문에 1로 설정

    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    for (int i = 1; i < n; i++) { 
        int max = 0;
        for (int j = 0; j < i; j++) { // 처음부터 현재 위치 - 1까지 체크
            if (vec[i] > vec[j]) { // 현재의 값보다 작은 값들 중에서 dp가 가장 큰 값의 1을 더한 값을 저장한다.
                if (dp[j] > max) { dp[i] = dp[j] + 1; max = dp[j]; }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) { // 가장 큰 값 찾기
        if (max < dp[i]) max = dp[i];
    }

    cout << max << endl;
}