#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> vec;
    vector<int> check(m, 0);

    for (int i = 0; i < n; i++) vec.push_back(i+1); // n개의 수를 저장한 벡터
    for (int i = 0; i < n - m; i++) check.push_back(1); // m개를 선택하기 위한 벡터

    sort(vec.begin(), vec.end());
    sort(check.begin(), check.end());

    do { // next_permutation 사용
        for (int i = 0; i < check.size(); i++) {
            if (!check[i]) printf("%d ", vec[i]);
        }
        printf("\n");
    } while(next_permutation(check.begin(), check.end()));
}