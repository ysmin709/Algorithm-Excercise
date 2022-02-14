#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, temp;
    cin >> n;

    set<int> s; // 중복은 필요 없으므로 set을 사용
    vector<int> t;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        s.insert(temp);
        t.push_back(temp);
    }

    vector<int> vec(s.begin(), s.end()); // set 정보를 vector로 옮기기

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) cout << lower_bound(vec.begin(), vec.end(), t[i]) - vec.begin() << " ";
}