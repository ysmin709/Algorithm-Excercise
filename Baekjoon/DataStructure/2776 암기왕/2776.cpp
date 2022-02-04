#include <iostream>
#include <map>
using namespace std;

map<int, bool> m;
int t, n;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> t;

	while (t--) {
		int temp;

		m.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			m.insert(pair<int, bool>(temp, true));
		}

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (m[temp]) cout << "1\n";
			else cout << "0\n";
		}
	}
}