#include <string>
#include <vector>
using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int idx, int sum) {
    if (idx == numbers.size()) { // tree의 마지막 노드일 때
        if (sum == target) answer++; // 값이 target과 같으면 answer 증가
        return;
    }
    dfs(numbers, target, idx + 1, sum + numbers[idx]); // 더하는 방향
    dfs(numbers, target, idx + 1, sum - numbers[idx]); // 빼는 방향
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    
    return answer;
}