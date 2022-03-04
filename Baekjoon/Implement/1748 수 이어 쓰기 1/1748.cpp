#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, answer = 0;
    cin >> n;

    int i = 1;
    while (i <= n) {
        answer += n - i + 1; // N까지 사용되는 해당 자리수의 숫자를 구한다.
        i *= 10;
    }
    
    cout << answer << "\n";
}