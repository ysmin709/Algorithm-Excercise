#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> temp;
    int check = -1;
    
    sort(numbers.begin(), numbers.end());
    
    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i+1; j < numbers.size(); j++) temp.push_back(numbers[i] + numbers[j]);
    }
    
    sort(temp.begin(), temp.end());
    
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] != check) {
            answer.push_back(temp[i]);
            check = temp[i];
        }
        else continue;
    }
    return answer;
}