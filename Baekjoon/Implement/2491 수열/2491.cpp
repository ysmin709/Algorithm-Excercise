#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int answer = 1, temp = 1, temp2 = 1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= arr[i + 1]) temp++;
        else temp = 1;

        if (arr[i] >= arr[i + 1]) temp2++;
        else temp2 = 1;

        int result = max(temp, temp2);
        answer = max(answer, result);
    }

    cout << answer << "\n";
}