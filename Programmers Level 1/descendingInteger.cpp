#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> v;
    int temp;
    
    while(n / 10 != 0) {
        temp = n % 10;
        v.push_back(temp);
        n /= 10;
    }
    v.push_back(n);
    
    sort(v.rbegin(), v.rend());
    
    long long mul = 1;
    for (int i = v.size()-1; i >= 0; i--) {
        answer += v[i] * mul;
        mul *= 10;
    } 
    
    return answer;
}