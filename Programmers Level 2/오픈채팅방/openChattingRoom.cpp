#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<pair<string, string>> temp;
    
    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string status, id, name;
        
        ss >> status;
        
        if (status == "Enter") {
            ss >> id; ss >> name;
            m[id] = name; // id별 이름 최신화
            temp.push_back(make_pair(status, id));
        }
        else if (status == "Leave") {
            ss >> id;
            temp.push_back(make_pair(status, id));
        }
        else if (status == "Change") {
            ss >> id; ss >> name;
            m[id] = name; // id별 이름 최신화
        }
    }
    
    for (int i = 0; i < temp.size(); i++) {
        string str = m[temp[i].second];
        if (temp[i].first == "Enter") str += "님이 들어왔습니다.";
        else str += "님이 나갔습니다.";
        answer.push_back(str);
    }
        
    return answer;
}