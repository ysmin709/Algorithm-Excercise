#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<long long, int> a, pair<long long, int> b) {
    return a.second < b.second;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<long long, int> m;

        for (int i = 0; i < n; i++) { // map에 번호 별 횟수 저장
            long long temp;
            cin >> temp;
            m[temp]++;
        }

        vector<pair<long long, int>> vec(m.begin(), m.end());

        sort(vec.rbegin(), vec.rend(), cmp); // map의 value 기준으로 내림차순 정렬

        if (vec[0].second > n / 2) cout << vec[0].first << "\n";
        else cout << "SYJKGW\n";
    }
}