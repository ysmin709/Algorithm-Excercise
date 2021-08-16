#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> stk;
    
    stk.push(make_pair(prices[0], 0));
    for (int i = 1; i < prices.size(); i++) { // 초기값은 넣었기 때문에 1부터 순회
        if (stk.top().first > prices[i]) { // 가격이 떨어졌는지 체크
            while (!stk.empty() && stk.top().first > prices[i]) { // 가격이 떨어진 모든 시점 체크
                answer[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
        }
        stk.push(make_pair(prices[i], i)); // 현재 값을 stack에 저장
    }
    
    while (!stk.empty()) { // 가격이 떨어지지 않은 시점들 처리
        answer[stk.top().second] = prices.size() - 1 - stk.top().second;
        stk.pop();
    }
    
    return answer;
}