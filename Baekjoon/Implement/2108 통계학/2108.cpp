#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt[8001] = { 0, };

int mode() {
    int max = 0, max_cnt = 0, mode = 0;

    for (int i = 0; i < 8001; i++) {
        if (max < cnt[i]) {
            max = cnt[i];
            max_cnt = 1;
            mode = i - 4000;
        }
        else if (max == cnt[i]) max_cnt++;

        if (max == cnt[i] && max_cnt == 2) mode = i - 4000;
    }

    return mode;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, sum = 0;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i] + 4000]++;
    }

    sort(arr.begin(), arr.end());

    cout << round((double) sum/n) << '\n';
    cout << arr[n / 2] << '\n';
    cout << mode() << '\n';
    cout << arr[n - 1] - arr[0];
}