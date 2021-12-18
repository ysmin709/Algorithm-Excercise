#include <iostream>
using namespace std;

long long solution(long long a, long long b, long long c) {
    if (!b) return 1;
    long long temp = solution(a, b / 2, c); // 재귀 사용
    if (b % 2) return temp * temp % c * a % c; // 홀수 짝수 구분
    else return temp * temp % c;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << solution(a, b, c) << endl;
}