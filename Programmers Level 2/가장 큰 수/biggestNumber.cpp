#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a; // 330과 303 중 큰 값을 선택하는 기준
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    
    for (int i = 0; i < numbers.size(); i++) temp.push_back(to_string(numbers[i]));
    sort(temp.begin(), temp.end(), cmp);
    for (int i = 0; i < temp.size(); i++) answer += temp[i];
    
    if (temp[0] == "0") return "0"; // temp[0]이 "0"인 상황은 값이 전부 0이기 때문에 "0"을 리턴
    else return answer;
}