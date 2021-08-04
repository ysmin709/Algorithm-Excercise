#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end()); // string을 사전순 정렬
    
    for (int i = 1; i < phone_book.size(); i++) { 
        if (phone_book[i].find(phone_book[i-1]) == 0) return false; // phone_book[i]가 phone_book[i-1]을 포함하고 있다면 false를 리턴
    }
    
    return answer; // 포함하지 않는다면 true 리턴
}