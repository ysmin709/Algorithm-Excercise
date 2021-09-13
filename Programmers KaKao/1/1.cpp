#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, vector<string>> Rm;
    
    for (int i = 0; i < report.size(); i++) {
        stringstream ss;
        ss.str(report[i]);
        string A = "", B = "";
        ss >> A;
        ss >> B;
        
        vector<string>::iterator it;
        it = find(Rm[B].begin(), Rm[B].end(), A);
        if (it == Rm[B].end()) Rm[B].push_back(A);
    }
    
    map<string, int> Nm;
    
    for (int i = 0; i < id_list.size(); i++) {
        if (Rm[id_list[i]].size() >= k) {
            for (int j = 0; j < Rm[id_list[i]].size(); j++) {
                Nm[Rm[id_list[i]][j]]++;
            }
        }
    }
    
    for (int i = 0; i < id_list.size(); i++) answer.push_back(Nm[id_list[i]]);
    
    return answer;
}