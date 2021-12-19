#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(b, a)); // 끝나는 시간을 기준으로 정렬하기 위해 b가 first로 들어간다.
    }

    sort(vec.begin(), vec.end());

    int start = 0;
    for (int i = 0; i < n; i++) {
        if (start <= vec[i].second) {
            start = vec[i].first;
            answer++;
        }
    }

    cout << answer << endl;
}