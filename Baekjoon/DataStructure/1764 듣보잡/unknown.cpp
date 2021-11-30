#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) { // map의 value를 기준으로 정렬
    if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
    int x, y;
    cin >> x >> y;

    map<string, int> m;
    for (int i = 0; i < x + y; i++) {
        string temp = "";
        cin >> temp;
        m[temp]++;
    }

    vector<pair<string, int>> vec(m.begin(), m.end()); // 정렬을 하기 위해 map 정보를 담은 vector 생성
    sort(vec.rbegin(), vec.rend(), cmp); // value 기준 정렬

    vector<string> res;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].second == 2) res.push_back(vec[i].first);
        else break;
    }
    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}