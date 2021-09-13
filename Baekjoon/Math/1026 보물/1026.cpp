#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;

    vector<int> a(n, 0);
    vector<int> b(n, 0);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end()); // 오름차순 정렬
    sort(b.rbegin(), b.rend()); // 내림차순 정렬

    for (int i = 0; i < n; i++) answer += a[i] * b[i];

    cout << answer << endl;
}