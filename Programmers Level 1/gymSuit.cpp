#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer;
    
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                break;
            }
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i] - 1 || reserve[j] == lost[i] + 1) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                break;
            }
        }
    }
        
    answer = n - lost.size();
    return answer;
}