#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int time = 0, numOfZero = 0;

    while (true) {
        time++;
        int numOfOne = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') numOfOne++;
            else numOfZero++;
        }

        vector<int> temp;
        s = "";
        s += '1';
        while(numOfOne != 1) {
            s += to_string(numOfOne % 2);
            numOfOne /= 2;
        }
        
        if (s.size() == 1) break;
    }
    
    answer.push_back(time);
    answer.push_back(numOfZero);
    
    return answer;
}