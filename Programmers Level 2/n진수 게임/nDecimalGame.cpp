#include <string>
#include <vector>

using namespace std;

string tenToN(int n, int target) { // 10진수를 N진수로 변환
    string temp = "";
    
    while (n >= target) {
        if (n % target > 9) temp.insert(temp.begin(), 1, 'A' + (n % target) % 10);
        else temp.insert(0, to_string(n % target));
        n /= target;
    }
    
    if (n > 9) temp.insert(temp.begin(), 1, 'A' + n % 10);
    else temp.insert(0, to_string(n));
    
    return temp;
}

string solution(int n, int t, int m, int p) {
    string answer = "", temp = "";
    int i = 0;
    
    while(temp.size() < t * m) { // t만큼 추출할 수 있도록 temp 문자열 구성
        temp += tenToN(i, n);
        i++;
    }
    
    for (int i = 0; i < t; i++) answer += temp[i*m+p-1]; // 필요한 부분 추출
    
    return answer;
}