#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    pair<pair<int, int>, char> Ncoor = make_pair(make_pair(0, 0), 'a'); // 좌표와 명령어를 저장하는 pair
    vector<pair<pair<int, int>, char>> arr; // 경로를 저장해줄 vector
    
    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'L') { Ncoor.first.first--; Ncoor.second = 'L'; }
        else if (dirs[i] == 'R') { Ncoor.first.first++; Ncoor.second = 'R'; }
        else if (dirs[i] == 'U') { Ncoor.first.second++; Ncoor.second = 'U'; }
        else if (dirs[i] == 'D') { Ncoor.first.second--; Ncoor.second = 'D'; }
        
        if (Ncoor.first.first < -5) { Ncoor.first.first++; continue; } // -5보다 작아지거나 5보다 커지면 이동하지 않는다.
        else if (Ncoor.first.first > 5) { Ncoor.first.first--; continue; }
        else if (Ncoor.first.second < -5) { Ncoor.first.second++; continue; }
        else if (Ncoor.first.second > 5) {Ncoor.first.second--; continue; }
        else {
            if (find(arr.begin(), arr.end(), Ncoor) != arr.end()) continue; // 경로가 저장된 vector에 현재 값이 있으면 answer가 증가하지 않는다.
            else {
                arr.push_back(Ncoor); // 각 명령에 따라 움직인 좌표와 명령 정보를 arr에 저장한다.
                pair<pair<int, int>, char> temp = Ncoor;
                
                if (Ncoor.second == 'L') { // 각 명령에 따라 다시 되돌아가는 경로를 arr에 저장한다.
                    temp.first.first++;
                    temp.second = 'R';
                    arr.push_back(temp);
                }
                else if (Ncoor.second == 'R') {
                    temp.first.first--;
                    temp.second = 'L';
                    arr.push_back(temp);
                }
                else if (Ncoor.second == 'U') {
                    temp.first.second--;
                    temp.second = 'D';
                    arr.push_back(temp);
                }
                else if (Ncoor.second == 'D') {
                    temp.first.second++;
                    temp.second = 'U';
                    arr.push_back(temp);
                }
            }
        }
        answer++;
    }
    
    
    return answer;
}