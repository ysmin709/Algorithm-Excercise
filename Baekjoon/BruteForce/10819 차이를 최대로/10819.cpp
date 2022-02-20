#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer;
int arr[9];
int sel[9];
bool check[9];

void dfs(int cnt) {
    if (cnt == n) {
        int temp = 0;
        
        for (int i = 0; i < n - 1; i++) temp += abs(sel[i] - sel[i + 1]);

        answer = max(answer, temp);

        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i]) continue;

        check[i] = true;
        sel[cnt] = arr[i];
        dfs(cnt + 1);
        check[i] = false;
    }
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    dfs(0);

    cout << answer << "\n";
}