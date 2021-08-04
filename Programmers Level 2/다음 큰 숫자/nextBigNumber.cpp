#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int numOfOne = 1, temp = n;
    while (temp != 1) { // 10진수를 이진화한다
        if (temp % 2) numOfOne++; // 1의 개수를 구한다
        temp /= 2;
    }
    
    int plus = 1;
    while (true) {
        int num = n + plus; // 기준 값에 반복문으로 1씩 더해준다
        int num_one = 1;
        
        while (num != 1) {
            if (num % 2) num_one++;
            if (num_one > numOfOne) break; // 1의 개수가 커지면 바로 다음 수로 넘어간다
            num /= 2;
        }
        
        if (num_one == numOfOne) return n + plus; // 1의 개수가 같다면
        plus++;
    }
}
