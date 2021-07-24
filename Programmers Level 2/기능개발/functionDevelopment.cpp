#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i = 0;
    int cnt = 0;
    
    while (i < speeds.size()) {
        if (progresses[i] >= 100) { cnt++; i++; }
        else if (progresses[i] < 100 && cnt > 0) {
            answer.push_back(cnt);
            cnt = 0;
            for (int j = i; j < speeds.size(); j++) progresses[j] += speeds[j];
        }
        else {
            for (int j = i; j < speeds.size(); j++) progresses[j] += speeds[j];
        }
    }
    answer.push_back(cnt);
    
    return answer;
}