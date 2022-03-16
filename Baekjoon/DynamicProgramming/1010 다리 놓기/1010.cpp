#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        long long answer = 1;

        int temp = 1;
        for (int i = m; i > m - n; i--) {
            answer *= i;
            answer /= temp;
            temp++;
        }
        
        cout << answer << "\n";
    }  
}