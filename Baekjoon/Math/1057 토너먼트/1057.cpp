#include <iostream>
using namespace std;

int main() {
    int n, a, b, answer = 1;
    cin >> n >> a >> b;
    
    while(n) {
        if ((a + 1) / 2 == (b + 1) / 2) break;

        a = (a + 1) / 2;
        b = (b + 1) / 2;
        n /= 2;
        
        answer++;
    }

    if (!n) cout << -1 << endl;
    else cout << answer << endl;
}