#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end()); // 오름차순 정렬
    sort(B.rbegin(), B.rend()); // 내림차순 정렬
    
    // A의 작은 값과 B의 큰 값을 순차적으로 곱하여 더하도록 했다.
    for (int i = 0; i < A.size(); i++) answer += A[i] * B[i];

    return answer;
}