#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, temp;
    cin >> n;

    map<int, bool> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        m[temp] = true;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (m[temp]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
}