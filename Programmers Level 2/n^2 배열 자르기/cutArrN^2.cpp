#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++) {
        answer.push_back(max(i / n, i % n) + 1); // 인덱스 값 중 큰 값의 1을 더한 값을 push한다.
    }
    
    return answer;
}