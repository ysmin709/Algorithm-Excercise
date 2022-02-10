#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int temp[10001];
    int n, k, cnt = 0;
    cin >> n >> k;

    for (int i = 2; i <= n; i++) temp[i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            if (temp[i*j]) {
                cnt++;
                temp[i*j] = 0;
                
                if (cnt == k) cout << i * j << endl;
            }
        }
    }
}