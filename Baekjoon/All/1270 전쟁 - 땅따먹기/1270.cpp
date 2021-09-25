#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        map<long long, long long> m;

        for (int j = 0; j < n; j++) {
            long long temp;
            cin >> temp;
            m[temp]++;
        }

        map<long long, long long>::iterator it;
        pair<long long, long long> max(0, 0);
        int cnt = 0;
        for (it = m.begin(); it != m.end(); it++) {
            if (n % 2) {
                if (it->second >= n / 2 + 1) { cnt++; max = make_pair(it->first, it->second); }
            }
            else {
                if (it->second >= n / 2) { cnt++; max = make_pair(it->first, it->second); }
            }
        }
        if (cnt == 0) cout << "SYJKGW" << endl;
        else if (cnt == 1) cout << max.first << endl;
        else cout << "SYJKGW" << endl;
    }
}