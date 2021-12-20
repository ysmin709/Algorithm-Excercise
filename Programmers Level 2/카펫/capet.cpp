#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = (brown + yellow) / 2; i > 0; i--) {
        if (!((brown + yellow) % i)) { // 총합을 높이로 나누었을 때 0이면
            if ((i - 2) * ((brown + yellow) / i - 2) == yellow) { // 테두리 부분은 갈색이기 때문에 -2를 한다.
                answer.push_back(i);
                answer.push_back((brown + yellow) / i);
                break;
            }
        }
    }
    
    return answer;
}