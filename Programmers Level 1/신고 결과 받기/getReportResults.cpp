#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<int> report_cnt(id_list.size(), 0);
    vector<vector<bool>> r_id_list(id_list.size(), vector<bool>(id_list.size(), false));
    
    for (int i = 0; i < report.size(); i++) {
        stringstream ss;
        ss.str(report[i]);
        string user, target;
        ss >> user; ss >> target;
        
        int user_idx = find(id_list.begin(), id_list.end(), user) - id_list.begin();
        int target_idx = find(id_list.begin(), id_list.end(), target) - id_list.begin();
        
        if (!r_id_list[user_idx][target_idx]) { // 동일 유저 신고 확인
            report_cnt[target_idx]++;
            r_id_list[user_idx][target_idx] = true;
        }
    }
    
    for (int i = 0; i < report_cnt.size(); i++) {
        if (report_cnt[i] >= k) {
            for (int j = 0; j < r_id_list.size(); j++) {
                if (r_id_list[j][i] == true) answer[j]++; // 해당 유저가 신고한 사람이 정지 됐다면 1증가
            }
        }
    }
    
    return answer;
}