#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b; // 길이가 같으면
    return a.size() < b.size(); // 길이가 다르면
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> vec;

    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end(), cmp);

    temp = vec[0];
    cout << vec[0] << endl;
    for (int i = 1; i < vec.size(); i++) {
        if (temp == vec[i]) continue; // 중복 체크
        else {
            temp = vec[i];
            cout << vec[i] << endl;
        }
    }
}