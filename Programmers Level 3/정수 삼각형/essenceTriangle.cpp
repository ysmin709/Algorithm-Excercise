#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
    
    dp[0][0] = triangle[0][0]; // 초기값만 저장한다.
    
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j]; // 제일 왼쪽은 바로 위의 값을 더한 후 저장한다.
            else if (j == i) dp[i][j] = dp[i-1][j-1] + triangle[i][j]; // 제일 오른쪽은 바로 위의 왼쪽 값을 더한 후 저장한다.
            else dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]); // 중간은 양쪽 위 값을 비교한 후 큰 값을 저장한다.
        }
    }
    
    for (int i = 0; i < triangle.size(); i++) {
        if (answer < dp[dp.size()-1][i]) answer = dp[dp.size()-1][i];
    }
    
    return answer;
}