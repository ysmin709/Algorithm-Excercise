#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    int answer = 0;
    int res = 10000;
    
    for (int i = 0; i < name.size(); i++) {
        int temp = i + 1;
        
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;
        
        while(name[temp] == 'A' && temp < name.size()) temp++;
        
        int n = name.size();
        res = min(i + n - temp + min(i, n - temp), res);
    }
    
    answer += res;
    
    return answer;
}

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6