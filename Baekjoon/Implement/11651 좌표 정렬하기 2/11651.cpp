#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(2));
    
    for (int i = 0; i < n; i++) cin >> vec[i][1] >> vec[i][0];
    
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) cout << vec[i][1] << " " << vec[i][0] << "\n";
}