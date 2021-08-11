#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<pair<string, int>> buf;
    
    for (int i = 0; i < clothes.size(); i++) {
        bool check = true;
        
        if (buf.size() == 0) buf.push_back(make_pair(clothes[i][1], 1)); // buf가 비어있다면 바로 넣는다.
        else { // buf에 값이 있다면
            for (int j = 0; j < buf.size(); j++) {
                if (buf[j].first == clothes[i][1]) { buf[j].second++; check = false; break; } // buf에 해당 옷의 종류가 있는지 확인
            }
            if (check) buf.push_back(make_pair(clothes[i][1], 1)); // 없다면 추가한다.
        }
    }
    
    for (int i = 0; i < buf.size(); i++) answer *= (buf[i].second+1); // 해당 종류의 옷을 입지 않은 경우의 수를 고려하기 위해 +1을 해준다.
    
    return --answer; // 아무것도 입지 않은 상황을 제외하기 위해 --를 한다.
}