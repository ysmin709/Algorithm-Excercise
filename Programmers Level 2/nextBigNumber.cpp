#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int numOfOne = 1, temp = n;
    while (temp != 1) {
        if (temp % 2) numOfOne++;
        temp /= 2;
    }
    
    int plus = 1;
    while (true) {
        int num = n + plus;
        int num_one = 1;
        
        while (num != 1) {
            if (num % 2) num_one++;
            if (num_one > numOfOne) break;
            num /= 2;
        }
        
        if (num_one == numOfOne) return n + plus;
        plus++;
    }
}
