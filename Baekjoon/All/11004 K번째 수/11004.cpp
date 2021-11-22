#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    vector<int> vec(n, 0);

    for (int i = 0; i < n; i++) scanf("%d", &vec[i]);

    sort(vec.begin(), vec.end());

    printf("%d\n", vec[k-1]);
}