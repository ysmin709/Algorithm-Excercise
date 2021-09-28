#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    vector<int> vec(n, 0);

    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    int temp = 0;
    for (int i = 0; i < n; i++) { temp += vec[i]; answer += temp; }

    cout << answer << endl;
}