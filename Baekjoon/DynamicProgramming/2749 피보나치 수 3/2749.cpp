#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int mod = 1000000;
    vector<int> vec(mod / 10 * 15, 0); // 피사노 주기 사용

    vec[0] = 0;
    vec[1] = 1;

    for (int i = 2; i <= mod / 10 * 15; i++) { 
        vec[i] = vec[i-1] + vec[i-2];
        vec[i] %= mod;
    }

    cout << vec[n % (mod /10 * 15)] << endl;
}