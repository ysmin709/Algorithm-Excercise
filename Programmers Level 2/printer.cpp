#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> temp(priorities.begin(), priorities.end());
    stack<int> stk;
    
    sort(temp.rbegin(), temp.rend());
    
    int i = 0, j = 0;
    while(stk.size() != temp.size()) {
        if (j == temp.size()) j = 0;
        if (temp[i] == priorities[j]) { 
            stk.push(priorities[j]);
            i++;
            priorities[j] = 0;
            if (priorities[location] == 0) break;
        }
        j++;
    }
    
    answer = stk.size();
    
    return answer;
}