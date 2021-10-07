#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    int answer = 1;

    while (a < b) { // 문제와 다르게 B→A로 체크
        if (b % 10 == 1) { b /= 10; answer++; } // 제일 뒤에 1이 있다면 삭제
        else if (!(b % 2)) { b /= 2; answer++; } // 2로 나누어지면 나누기
        else if (b % 2) { answer = -1; break; } // 제일 뒤가 1도 아니고 2로 나누어지지도 않는다면 조건 성립이 안되므로 -1 출력
    }
    
    if (a != b) answer = -1; // a == b가 성립하지 않으므로 -1 출력

    cout << answer << endl;
}