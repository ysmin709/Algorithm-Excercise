#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> vec(n, 0);

    for (int i = 0; i < n; i++) scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) printf("%d\n", vec[i]);
}