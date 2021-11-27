#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());
    
    do { // 모든 순열 비교
        vector<vector<int>> vec(dungeons.size(), vector<int>(2, 0));
        int temp = k, cnt = 0;
        
        for (int i = 0; i < dungeons.size(); i++ ) vec[i] = dungeons[i];
        
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i][0] > temp) continue; // 최소 필요 피로도 부족
            else { temp -= vec[i][1]; cnt++; }
            if (temp == 0) break; // 0으로 떨어지면 반복문 중지
            else if (temp < 0) { cnt--; break; } // 0보다 작아지면 피로도가 부족한 것이므로 cnt 감소 후 반복문 중지
        }
        
        answer = max(answer, cnt); // 가장 많이 방문하는 경우의 수를 answer로 설정
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}