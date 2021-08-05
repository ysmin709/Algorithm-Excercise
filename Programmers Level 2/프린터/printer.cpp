#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> temp(priorities.begin(), priorities.end());
    stack<int> stk;
    
    sort(temp.rbegin(), temp.rend()); // 내림차순 정렬
    
    int i = 0, j = 0;
    while(stk.size() != temp.size()) {
        if (j == temp.size()) j = 0; // 우선순위에서 밀려서 지나친 것들을 처리
        if (temp[i] == priorities[j]) { // 우선순위 순서대로 작업 수행
            stk.push(priorities[j]);
            i++;
            priorities[j] = 0;
            if (priorities[location] == 0) break; // 우선순위가 0이면 끝
        }
        j++;
    }
    
    answer = stk.size();
    
    return answer;
}