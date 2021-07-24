#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> stk;
    
    stk.push(make_pair(prices[0], 0));
    for (int i = 1; i < prices.size(); i++) {
        if (stk.top().first > prices[i]) {
            while (!stk.empty() && stk.top().first > prices[i]) {
                answer[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push(make_pair(prices[i], i));
        }
        else stk.push(make_pair(prices[i], i));
    }
    
    while (!stk.empty()) {
        answer[stk.top().second] = prices.size() - 1 - stk.top().second;
        stk.pop();
    }
    
    return answer;
}