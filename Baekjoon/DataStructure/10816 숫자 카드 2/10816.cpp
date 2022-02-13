#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, temp;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << upper_bound(vec.begin(), vec.end(), temp) - lower_bound(vec.begin(), vec.end(), temp) << " "; // 해당 숫자를 가진 카드 개수 체크
    }
}