#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool arr[1000001];

    for (int i = n; i <= m; i++) arr[i] = true;
    arr[0] = false; arr[1] = false; // 소수는 2부터 존재하므로 false

    for (int i = 2; i <= sqrt(m); i++) {
        for (int j = i + i; j <= m; j += i) arr[j] = false; // 에라토스테네스의 체 사용
    }

    for (int i = n; i <= m; i++) {
        if (arr[i]) printf("%d\n", i);
    }
}