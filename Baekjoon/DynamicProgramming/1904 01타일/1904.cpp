#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> vec;
    long long temp;

    for (int i = 0; i < 3; i++) vec.push_back(i);

    for (int i = 3; i <= n; i++) {
        temp = vec[i-1] + vec[i-2];
        vec.push_back(temp % 15746);
    }

    cout << vec[n] % 15746 << "\n";
}