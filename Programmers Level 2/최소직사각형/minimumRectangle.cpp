#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0, h = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        int big = 0, small = 0;
        if (sizes[i][0] >= sizes[i][1]) { big = sizes[i][0], small = sizes[i][1]; } // 큰 값 체크
        else { big = sizes[i][1], small = sizes[i][0]; }
        
        if (big > w) w = big; // 가로 값이 sizes[i]의 큰 값보다 작다면 최신화
        if (small > h) h = small; // 세로 값이 sizes[i]의 작은 값보다 작다면 최신화
    }
    
    answer = w * h;
    return answer;
}