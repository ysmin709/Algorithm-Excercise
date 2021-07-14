#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr;
    
    for (int i = 0; i < s.size(); i++) {
        string temp = "";
        if (s[i] == ' ') continue;
        else if (s[i] >= '0' && s[i] <= '9') {
            while(s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
                i++;
            }
            arr.push_back(stoi(temp));
        }
        else if (s[i] == '-') {
            temp += '-';
            i++;
            while(s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
                i++;
            }
            arr.push_back(stoi(temp));
        }
    }
    
    int min = arr[0], max = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);
    
    return answer;
}