#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n + 1; i++) {
        if ((n % i) == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> bit;
    
    while (n > 0) {
        bit.push_back(n % k);
        n /= k;
    }
    reverse(bit.begin(), bit.end());
    
    string temp = "";
    for (int i = 0; i < bit.size(); i++) {
        if (bit[i] != 0) temp += to_string(bit[i]);
        else {
            if (temp.size() == 0) continue;
            else {
                if (isPrime(stoll(temp))) answer++;
                temp = "";
            }
        }
    }
    
    if (temp.size() != 0) {
        if (isPrime(stoll(temp))) answer++;
    }
    
    return answer;
}