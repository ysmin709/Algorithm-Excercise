#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

#define ll long long

int main() {
    int n;
    scanf("%d", &n);

    priority_queue<ll, vector<ll>, less<ll>> pq; // 내림차순 우선순위 큐

    for (int i = 0; i < n; i++) {
        ll temp;
        scanf("%lld", &temp);

        if (!temp) {
            if (pq.empty()) printf("%d\n", 0); // pq가 비어있으면 0 출력
            else {
                printf("%lld\n", pq.top()); // 현재 pq의 제일 큰 수 출력
                pq.pop();
            }
        }
        else pq.push(temp); // 내림차순으로 pq에 저장
    }
}