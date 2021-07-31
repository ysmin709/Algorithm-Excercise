#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end()); // 오름차순 우선순위 큐
    
    while (q.size() > 1) {
        int temp = 0;
        if (q.top() < K) {
            temp += q.top(); q.pop(); // 가장 맵지 않은 음식
            temp += q.top() * 2; q.pop(); // 두 번째로 맵지 않은 음식
            q.push(temp); // 연산값을 우선순위 큐에 넣는다
            answer++;
        }
        else break; // 가장 작은 수가 K보다 크면 성공한 것이므로 break
    }
    
    if (q.top() < K && q.size() <= 1) return -1; // 우선순위 큐에 1개의 값만 있고 그 값이 K보다 작다면 실패
    
    return answer;
}