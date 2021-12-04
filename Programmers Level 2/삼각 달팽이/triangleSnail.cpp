#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    
    int top = 0, bottom = n-1, idx_X = 0;
    int standard = 0, labs = 0, cnt = 1;
    
    for (int i = 1; i <= n; i++) standard += i;
    
    while(cnt <= standard) {
        for (int i = top; i <= bottom; i++) { // top을 기준으로 bottom까지 이동
            vec[i][idx_X] = cnt;
            cnt++;
        }
        idx_X++;
        top++;
        for (int i = idx_X; i <= bottom - labs; i++) { // bottom에서 오른쪽으로 이동
            vec[bottom][i] = cnt;
            cnt++;
        }
        int temp = bottom - labs - 1;
        bottom--;
        for (int i = bottom; i >= top; i--) { // bottom에서 top까지 이동
            vec[i][temp] = cnt;
            cnt++;
            temp--;
        }
        top++;
        labs++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i][j] == 0) break;
            answer.push_back(vec[i][j]);
        }
    }
    
    return answer;
}