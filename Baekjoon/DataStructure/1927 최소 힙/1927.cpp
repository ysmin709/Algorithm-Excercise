#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq; // 2^31까지 이므로 ull 사용

    for (int i = 0; i < n; i++) {
        unsigned long long temp;
        scanf("%llu", &temp);

        if (!temp) { // 0이 입력되면
            if (pq.empty()) printf("%d\n", 0); // pq가 비어 있으면 0 출력
            else { // pq가 비어있지 않다면
                printf("%llu\n", pq.top()); // pq의 top 출력 후 pop
                pq.pop();
            }
        }
        else pq.push(temp); // 자연수가 입력되면 push
    }
}