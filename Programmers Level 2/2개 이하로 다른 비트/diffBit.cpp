#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) { answer.push_back(numbers[i]+1); continue; } // 짝수는 1만 더했을 때 조건이 성립함
        else {
            long long add = 1;
            while (true) {
                if ((numbers[i] & add) == 0) break;
                add *= 2; // 다음 비트
            }
            answer.push_back(numbers[i] + add / 2); 
        }
    }
    
    return answer;
}