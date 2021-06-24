#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr;
    int mul = 1;
    
    while (n != 0) {
        arr.insert(arr.begin(), n % 3);
        n /= 3;
    }
    
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) answer += arr[i];
        else {
            mul *= 3;
            answer += arr[i] * mul;
        }  
    }
    
    return answer;
}