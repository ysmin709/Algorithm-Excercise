#include <iostream>
using namespace std;

int main() {
    int a, b, v, answer = 1;
    cin >> a >> b >> v;

    if (!((v - a) % (a - b))) cout << (v - a) / (a - b) + 1 << endl;
    else cout << (v - a) / (a - b) + 2 << endl;
}