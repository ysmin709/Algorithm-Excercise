#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> arr;
    
    int i = 0;
    int j = 0;
    
    while(i < 3) {
        int num = 0;
        string temp = "";
        
        if (dartResult[j] == '1') {
            if (dartResult[j+1] == '0') {
                temp += dartResult[j];
                temp += dartResult[j+1];
                j += 2;
                while((dartResult[j] >= '0' && dartResult[j] <= '9' || j >= dartResult.size()) == false) {
                    temp += dartResult[j];
                    j++;
                }
            }
            else {
                temp += dartResult[j];
                j++;
                while((dartResult[j] >= '0' && dartResult[j] <= '9' || j >= dartResult.size()) == false) {
                    temp += dartResult[j];
                    j++;
                }   
            }
        }
        else if (dartResult[j] >= '0' && dartResult[j] <= '9') {
            temp += dartResult[j];
            j++;
            while((dartResult[j] >= '0' && dartResult[j] <= '9' || j >= dartResult.size()) == false) {
                temp += dartResult[j];
                j++;
            }
        }
        
        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] == '1') {
                if (temp[k+1] == '0') { num = 10; k++; }
                else { num = 1; k++; }
            }
            else if (temp[k] >= '0' && temp[k] <= '9') num = temp[k] - '0';
            else if (temp[k] == 'D') num *= num;
            else if (temp[k] == 'T') num *= num * num;
            else if (temp[k] == '*') {
                if (arr.size() == 0) num *= 2;
                else if (arr.size() > 0) { arr[i-1] *= 2; num *= 2; }
            }
            else if (temp[k] == '#') num -= 2 * num;
        }
        arr.push_back(num);
        i++;
    }
    
    for (int i = 0 ; i < arr.size(); i++) answer += arr[i];
    
    return answer;
}