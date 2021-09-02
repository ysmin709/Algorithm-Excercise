#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int temp = 0, mul = 1, answer = 0;
    while(temp < n) {
        if (temp == 0) temp++; // 처음 1칸은 1 하나이기 때문에 1만 증가한다.
        else { temp += mul * 6; mul++; } // 1에서 떨어진 칸수 * 6을 더한다.
        answer++;
    }

    cout << answer << endl;
}