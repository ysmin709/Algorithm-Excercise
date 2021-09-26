#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while (n > 0) {
        if (n % 3 == 0) answer = "4" + answer;
        else if (n % 3 == 1) answer = "1" + answer;
        else answer = "2" + answer;
        
        if (!(n % 3)) n = n / 3 - 1;
        else n /= 3;
    }
    
    return answer;
}