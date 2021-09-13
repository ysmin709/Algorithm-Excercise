#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end()); // 오름차순 정렬
    
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (numbers[j] == i) j++; // 있는 수는 넘어간다.
        else { answer += i; } // 없는 수는 answer에 더한다.
    }
    
    return answer;
}