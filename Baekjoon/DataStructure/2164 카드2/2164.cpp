#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec;

    for (int i = 1; i <= n; i++) vec.push_back(i);

    int idx = 0;
    while(idx < vec.size()-1) {
        idx++;
        vec.push_back(vec[idx]);
        idx++;
    }

    cout << vec[vec.size()-1] << endl;
}