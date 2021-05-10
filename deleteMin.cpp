#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min, idx;
    
    if (arr.size() == 1) {
        arr.erase(arr.begin());
        arr.push_back(-1);
    }
    else {
        min = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < min) { min = arr[i]; idx = i; }
        }
        arr.erase(arr.begin()+idx);
    }
    answer = arr;
    
    return answer;
}