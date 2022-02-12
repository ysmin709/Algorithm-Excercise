#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<int, pair<int, int>> m; // 입차 정보 저장
    map<int, int> cost; // 차가 하루 동안 총 있었던 시간을 저장
    map<int, bool> check; // 차가 주차장에 있는지 체크
    
    for (int i = 0; i < records.size(); i++) {
        stringstream ss;
        ss.str(records[i]);
        string time, number, status;
        ss >> time; ss >> number; ss >> status; // 입출입 정보 받기
        
        string temp = "";
        temp += time[0]; temp += time[1];
        int hour = stoi(temp);
        
        temp = "";
        temp += time[3]; temp += time[4];
        int minute = stoi(temp);
        int num = stoi(number);
        
        if (status[0] == 'I') { // 차가 들어왔다면
            m[num] = make_pair(hour, minute);
            check[num] = true;
        }
        else { // 차가 나갔다면
            hour -= m[num].first;
            if (minute >= m[num].second) minute -= m[num].second;
            else {
                hour--;
                minute += 60 - m[num].second;
            }
            
            cost[num] += hour * 60 + minute;
            check[num] = false;
        }
    }
    
    vector<pair<int, bool>> temp(check.begin(), check.end());
    
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i].second) {
            int hour = 23, minute = 59, num = temp[i].first;
            hour -= m[num].first;
            if (minute >= m[num].second) minute -= m[num].second;
            else {
                hour--;
                minute += 60 - m[num].second;
            }
            
            cost[num] += hour * 60 + minute;
            check[num] = false;            
        }
    }
    
    vector<pair<int, int>> result(cost.begin(), cost.end());
    for (int i = 0; i < result.size(); i++) {
        int t = result[i].second, res = 0;
        
        t -= fees[0];
        res += fees[1];
        while(t > 0) {
            t -= fees[2];
            res += fees[3];
        }
        
        answer.push_back(res);
    }
    
    return answer;
}