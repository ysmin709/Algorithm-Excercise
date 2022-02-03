#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long cnt = 0;
    
    priority_queue<int, vector<int>, less<int>> pq;
    
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
        cnt += works[i];
    }
    
    if (cnt - n < 1) return answer; // 야근을 안 해도 된다면 0 리턴
    
    for (int i = 0; i < n; i++) { // 가장 큰 수부터 작게 만들어 다시 pq에 넣는다.
        int temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
    }
    
    while (!pq.empty()) { // 각 업무의 피로도 계산
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}