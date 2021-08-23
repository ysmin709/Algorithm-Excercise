#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int Fcnt = n / 5; // 5키로그램 봉지
    int Tcnt = 0; // 3키로그램 봉지
    n %= 5; // 5키로를 최대로 사용했을 때를 기준으로 %= 5 연산을 한다.
    
    if (n == 0) cout << Fcnt << endl; // 5키로 봉지로 나누어 떨어지면 바로 출력
    else {
        while (n != 0) { // 나누어 떨어지면 종료
            if (n < 3) { n += 5; Fcnt--; } // 3보다 작으면 3키로 봉지를 사용할 수 없으므로 5키로 봉지 1개를 뺀다.
            else {
                Tcnt += n / 3; // 3보다 크면 3으로 나눈다.
                n %= 3;
            }
            if (Fcnt == -1) { cout << -1 << endl; return 0; } // 실패한 경우의 수
        }
        cout <<  Fcnt + Tcnt << endl; // 2개의 봉지 개수를 합해서 출력
    }
}