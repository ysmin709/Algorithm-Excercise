#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for (int i = 0; i < scores.size(); i++) {
        double sum = 0;
        int min = 101, max = 0;
        bool check = true; // 자신에게 준 점수가 유일한 최소인지 최저인지 체크하는 변수
        
        vector<int> temp;
        for (int j = 0; j < scores[i].size(); j++) { // 한 사람이 받은 점수를 vector에 넣는다.
            if (min > scores[j][i]) min = scores[j][i];
            if (max < scores[j][i]) max = scores[j][i];
            sum += scores[j][i];
            temp.push_back(scores[j][i]);
        }
        
        if (scores[i][i] != min && scores[i][i] != max) { sum /= scores.size(); check = false; } // 자신에게 준 점수가 최저도 아니고 최고도 아닐 때
        else if (scores[i][i] == min) { // 자신에게 준 점수가 최저일 때
            for (int j = 0; j < scores.size(); j++) {
                if (i == j) continue;
                else if (scores[j][i] == min) { sum /= scores.size(); check = false; break; } // 유일한 최저점인지 체크
            }
        }
        else { // 자신에게 준 점수가 최고일 때
            for (int j = 0; j < scores.size(); j++) {
                if (i == j) continue;
                else if (scores[j][i] == max) { sum /= scores.size(); check = false; break; } // 유일한 최고점인지 체크
            }
        }
        
        if (check) { sum -= scores[i][i]; sum /= scores.size() - 1; } // 유일한 최고점 or 최저점일 때
        
        if (sum >= 90) answer += 'A';
        else if (sum >= 80) answer += 'B';
        else if (sum >= 70) answer += 'C';
        else if (sum >= 50) answer += 'D';
        else answer += 'F';
    }
    
    return answer;
}