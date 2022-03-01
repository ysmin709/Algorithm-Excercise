#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
    cin >> t;

    while (t--) {
        int c, v;
        cin >> c >> v;

        vector<vector<int>> vec(v + 1, vector<int>(c));
        map<int, int> m;

        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < c; j++) {
                cin >> vec[i][j];
                if (j == 0) m[vec[i][j]]++;
            }
        }

        vector<pair<int, int>> temp(m.begin(), m.end());
        sort(temp.rbegin(), temp.rend(), cmp); // map의 value 기준 내림차순 정렬

        if (temp[0].second > v / 2) { // 과반수 이상 득표 했다면
            cout << temp[0].first << " " << 1 << "\n";
            continue;
        }
        else if (temp.size() > 2) temp.erase(temp.begin() + 2, temp.end()); // 2회차 투표를 위해 2명의 후보 선정

        temp[0].second = 0; temp[1].second = 0;

        for (int i = 0; i < vec.size(); i++) {
            bool check = true;
            for (int j = 0; j < vec[i].size(); j++) {
                for (int k = 0; k < temp.size(); k++) {
                    if (vec[i][j] == temp[k].first) {
                        temp[k].second++;
                        check = false;
                        break;
                    }
                }
                if (!check) break;
            }
        }

        sort(temp.rbegin(), temp.rend(), cmp); // value 기준 내림차순 정렬

        cout << temp[0].first << " " << 2 << "\n";
    }
}