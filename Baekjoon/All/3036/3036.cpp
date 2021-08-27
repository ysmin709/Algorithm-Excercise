#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int t, standard, n;
    cin >> t >> standard;

    for (int i = 0; i < t-1; i++) {
        cin >> n;
        int divide = gcd(standard, n); // 최소공배수 찾기
        cout << standard / divide << '/' << n / divide << endl; // 최소공배수로 통분한 값 출력
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}