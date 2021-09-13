#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, pair<int, string>> IOm; // 출입시간 관리 map
    map<string, int> Rm; // 총 주차시간 map
    
    for (int i = 0; i < records.size(); i++) {
        string time, number, status;
        stringstream ss;
        ss.str(records[i]);
        ss >> time; ss >> number; ss >> status;
        time.erase(time.begin()+2);
        int minute = 0;
        
        minute += (time[0] - '0') * 600; minute += (time[1] - '0') * 60;
        minute += (time[2] - '0') * 10; minute += time[3] - '0';
        
        if (status == "IN") IOm[number] = make_pair(minute, "IN");
        else {
            Rm[number] += minute - IOm[number].first;
            IOm[number] = make_pair(minute, "OUT");
        }
    }

    
    map<string, pair<int, string>>::iterator it;
    for (it = IOm.begin(); it != IOm.end(); it++) {
        if (it->second.second == "IN") Rm[it->first] += 1439 - IOm[it->first].first;
    }
    
    map<string, int>::iterator iter;
    for (iter = Rm.begin(); iter != Rm.end(); iter++) {
        if (iter->second <= fees[0]) answer.push_back(fees[1]);
        else {
            double temp = iter->second;
            temp -= fees[0];
            int res = fees[1];
            while (temp > 0) {
                temp -= fees[2];
                res += fees[3];
            }
            answer.push_back(res);
        }
    }
    
    return answer;
}