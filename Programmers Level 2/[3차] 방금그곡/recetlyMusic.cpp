#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<pair<int, pair<int, string>>> vec;
    int cnt = 0;
    
    for (int i = 0; i < musicinfos.size(); i++) {
        string sHour = musicinfos[i].substr(0, 2);
        string sMin = musicinfos[i].substr(3, 2);
        string eHour = musicinfos[i].substr(6, 2);
        string eMin = musicinfos[i].substr(9, 2);
        
        int hour = stoi(eHour) - stoi(sHour);
        int minute = 0;
        if (stoi(eMin) < stoi(sMin)) {
            hour--;
            minute = 60 + stoi(eMin) - stoi(sMin);
        }
        else minute = stoi(eMin) - stoi(sMin);
        
        int time = hour * 60 + minute; // 총 재생시간
        
        string music = "";
        int j = 12;
        while (musicinfos[i][j] != ',') {
            music += musicinfos[i][j];
            j++;
        }
        
        j++;
        string score = "";
        while(j < musicinfos[i].size()) {
            if (musicinfos[i][j] == '#') score[score.size()-1] += 7; // C# -> J 이런 식으로 치환해서 char 형으로 만든다.
            else score += musicinfos[i][j];
            j++;
        }
        
        int score_size = score.size(); // score.size()는 계속 바뀌므로 처음 사이즈를 변수에 저장
        if (time > score.size()) {
            for (int j = 1; j < time / score_size; j++) score += score.substr(0, score_size);
            score += score.substr(0, time % score_size); 
        }
        else score = score.substr(0, time);
        
        string temp = "";
        for (int j = 0; j < m.size(); j++) {
            if (m[j] == '#') temp[temp.size()-1] += 7;
            else temp += m[j];
        }
        
        if (score.find(temp) != string::npos) {
            vec.push_back(make_pair(time, make_pair(cnt, music)));
            cnt++;
        }
    }
    
    if (cnt == 0) answer = "(None)";
    else {
        vector<pair<int, string>> tmp_vec;
        sort(vec.rbegin(), vec.rend()); // 재생시간 기준으로 내림차순 정렬
        if (vec[0].first == vec[1].first) {
            int i = 0;
            int standard = vec[0].first;
            while(vec[i].first == standard) {
                tmp_vec.push_back(vec[i].second);
                i++;
            }
            
            sort(tmp_vec.begin(), tmp_vec.end()); // 입력된 음악 순서 오름차순 정렬
            
            answer = tmp_vec[0].second;
        }
        else answer = vec[0].second.second;
    }
    
    return answer;
}