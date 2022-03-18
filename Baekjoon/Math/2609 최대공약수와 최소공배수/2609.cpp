#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int temp = a % b;
    
    while(temp != 0) {
        a = b;
        b = temp;
        temp = a % b;
    }

    return b;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int x, y;
    cin >> x >> y;

    cout << gcd(x, y) << "\n";
    cout << (x * y) / gcd(x, y);
}