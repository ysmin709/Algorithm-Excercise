#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int temp = x;
    int sum = 0;
    
    while(temp >= 10) {
        sum += temp % 10;
        temp /= 10;
    }
    sum += temp;
    
    if (x % sum == 0) return true;
    else return false;
}