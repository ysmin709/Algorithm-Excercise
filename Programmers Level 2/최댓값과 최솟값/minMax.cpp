#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr;
    
    for (int i = 0; i < s.size(); i++) {
        string temp = "";
        if (s[i] == ' ') continue; // 숫자만 넣기 위해 공백일 때는 넘긴다.
        else if (s[i] >= '0' && s[i] <= '9') {
            while(s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
                i++;
            }
            arr.push_back(stoi(temp)); // string을 int형으로 변환하여 vector에 넣는다.
        }
        else if (s[i] == '-') { // 음수 처리
            temp += '-';
            i++;
            while(s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
                i++;
            }
            arr.push_back(stoi(temp));
        }
    }
    
    int min = arr[0], max = arr[0]; // min, max값 체크
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    answer += to_string(min); // string을 리턴해야 하기 때문에 string으로 변환
    answer += ' ';
    answer += to_string(max);
    
    return answer;
}