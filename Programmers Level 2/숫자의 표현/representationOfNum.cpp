#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) { // 전체 탐색
        int temp = 0;
        for (int j = 0; j <= n; j++) {
            temp += i + j;
            if (temp == n) { answer++; break; } // 값이 딱 맞아 떨어지면 answer 증가
            else if (temp > n) break; // temp가 n보다 크면 다음으로 넘어간다.
        }
    }
    
    return answer;
}