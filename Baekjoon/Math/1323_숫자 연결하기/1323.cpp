#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vec; // 나머지를 저장하는 벡터
    string str = "";
    vector<int>::iterator it; // 저장된 나머지를 검사하는 it

    int cnt = 0;
    while (true) {
        str += to_string(n);
        cnt++;
        int check = stoull(str) % k; // 나머지 값과 N의 최대값을 합치면 int형 범위를 벗어나기 때문에 unsingned long long을 사용
        if (!check) { cout << cnt << endl; return 0; } // 나누어 떨어지면 현재 cnt값 출력
        else {
            str = to_string(check);
            it = find(vec.begin(), vec.end(), check); // 나머지가 반복되는지 확인
            if (it != vec.end()) { cout << -1 << endl; return 0; } // 반복됐다면 나누어 떨어지지 않는 값이기 때문에 -1 출력
            else vec.push_back(check);
        }
    }
}