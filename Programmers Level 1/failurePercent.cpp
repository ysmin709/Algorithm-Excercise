#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> per;
    
    for (int i = 1; i <= N; i++) {
        double failUser = 0, sucUser = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] > i) sucUser++;
            else if (stages[j] == i) { sucUser++; failUser++; } 
        }
        if (failUser == 0 || sucUser == 0) per.push_back(0);
        else per.push_back(failUser / sucUser);
    }
    
    vector<double> temp(per.begin(), per.end());
    sort(temp.rbegin(), temp.rend());
    
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < per.size(); j++) {
            if (temp[i] == per[j]) {
                answer.push_back(j+1);
                per[j] = -1;
                break;
            }
        }
    }
    
    
    return answer;
}