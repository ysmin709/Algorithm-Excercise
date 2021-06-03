#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> measure;
    
    int min = 0, max = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!(n % i)) measure.push_back(i);
    }
    for (int i = 0; i < measure.size(); i++) {
        if (!(m % measure[i]) && max < measure[i]) max = measure[i];
    }
    answer.push_back(max);
    
    int i = 1, j = 1;
    while(true) {
        if (n * i < m * j) i++;
        else if (n * i > m * j) j++;
        else {
            answer.push_back(n * i);
            break;
        }
    }
    
    return answer;
}