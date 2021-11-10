#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
	int a = (int)sqrt(n);
	for (int i = 2; i <= a; i++) if (n % i == 0) return false;
	return true;
}

int main() {
    int t, n, answer = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        if (isPrime(n)) answer++;
    }

    cout << answer << endl;
}