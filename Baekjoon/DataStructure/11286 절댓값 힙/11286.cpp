#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

#define ll long long

int main() {
    int n;
    scanf("%d", &n);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // 2의 32승까지 사용하므로 long long 자료형 사용

    for (int i = 0; i < n; i++) {
        ll temp;
        scanf("%lld", &temp);

        if (temp == 0) {
            if (pq.empty()) printf("%d\n", 0); // pq가 비어있다면 0 출력
            else {
                printf("%lld\n", pq.top().second); // 절대값이 아닌 입력받은 정수 출력
                pq.pop();
            }
        }
        else pq.push(make_pair(llabs(temp), temp)); // first에 입력 받은 정수의 절대값을 넣고, second에 정수를 넣는다.
    }
}