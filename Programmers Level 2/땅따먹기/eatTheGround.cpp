#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> land) {
    for (int i = 0; i < land.size()-1; i++) {
        for (int j = 0; j < 4; j++) {
            int max = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue; // 같은 열은 제외
                else if (land[i][k] > max) max = land[i][k]; // 3개의 열 중 가장 큰 값
            }
            land[i+1][j] += max; // 해당 위치로 갔을 때 가장 큰 값을 더해준다.
        }
    }
    
    int max = 0;
    for (int i = 0; i < 4; i++) if (land[land.size()-1][i] > max) max = land[land.size()-1][i]; // 제일 마지막 행 중 가장 큰 값을 찾는다.

    return max;
}