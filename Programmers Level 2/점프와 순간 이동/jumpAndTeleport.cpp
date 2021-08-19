using namespace std;

int solution(int n) {
    int answer = 0;
    
    while (n != 1) {
        if (n % 2) { n--; answer++; } // n이 홀수가 되면 --연산을 진행하고 answer를 증가한다.
        else n /= 2; // 짝수면 순간 이동
    }

    return ++answer; // answer가 1이 되어야만 순간 이동을 할 수 있으므로 1을 증가하고 return한다.
}