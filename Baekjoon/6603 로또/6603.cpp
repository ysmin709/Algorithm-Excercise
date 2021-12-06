#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(true) {
        cin >> n;
        if (n == 0) break;

        vector<int> vec(n, 0);
        vector<int> check(6, 0); // nC6을 만들어주는 vector

        for (int i = 0; i < n; i++) cin >> vec[i];
        for (int i = 0; i < n - 6; i++) check.push_back(1);

        sort(vec.begin(), vec.end());
        sort(check.begin(), check.end());

        do { // 가능한 모든 순열 출력
            for (int i = 0; i < check.size(); i++) {
                if (!check[i]) cout << vec[i] << " ";
            }
            cout << endl;
        } while(next_permutation(check.begin(), check.end()));
        cout << endl;
    }
}