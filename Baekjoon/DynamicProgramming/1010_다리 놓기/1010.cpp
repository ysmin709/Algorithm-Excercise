#include <iostream>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        long long answer = 1;

        if (n > m / 2) n = m - n;
        for (int j = 0; j < n; j++) answer *= m - j; // 조합의 분자
        for (int j = 1; j <= n; j++) answer /= j; // 조합의 분모
        
        cout << answer << endl;
    }
}