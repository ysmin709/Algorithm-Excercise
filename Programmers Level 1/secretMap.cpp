#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> temp1;
    vector<string> temp2;
    
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2) s += '1';
            else s += '0';
            arr1[i] /= 2;
        }
        temp1.push_back(s);
    }
    
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (arr2[i] % 2) s += '1';
            else s += '0';
            arr2[i] /= 2;
        }
        temp2.push_back(s);
    }
    
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = n-1; j >= 0; j--) {
            if (temp1[i][j] == '1' || temp2[i][j] == '1') s += '#';
            else s += ' ';
        }
        answer.push_back(s);
    }
    
    return answer;
}