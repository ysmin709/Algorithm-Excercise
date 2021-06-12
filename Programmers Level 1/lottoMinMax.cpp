#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int Lcnt = 0, Hcnt = 0;
    
    for (int i = 0; i < lottos.size(); i++) {
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) { Lcnt++; Hcnt++; break; }
            else if (lottos[i] == 0) { Hcnt++; break; }
        }
    }
    if (Hcnt >= 2) answer.push_back(7-Hcnt);
    else answer.push_back(lottos.size());
    if (Lcnt >= 2) answer.push_back(7-Lcnt);
    else answer.push_back(lottos.size());
    
    return answer;
}