#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

bool prime(int n) { // 소수 판별
    if (n < 2) return false;
	int a = (int)sqrt(n);
	for (int i = 2; i <= a; i++) if (n % i == 0) return false;
	return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> vec;
    map<int, int> m;
    
    sort(numbers.begin(), numbers.end());
    
    for (int i = 0; i < numbers.size(); i++) vec.push_back(numbers[i]);
    
    for (int i = 1; i <= numbers.size(); i++) {
        vector<bool> check(numbers.size() - i, false); // n자리 경우의 수를 모두 체크
        check.insert(check.end(), i, true);
        do {
            string temp = "";
            for (int j = 0; j < numbers.size(); j++) { // check가 true일 때만 temp에 더해준다.
                if (check[j]) temp += vec[j];
            }
            
            if (prime(stoi(temp)) && !m[stoi(temp)]) { // 011과 11을 중복해서 처리하지 않기 위해 map 사용
                answer++;
                m[stoi(temp)] = 1;
            }
        } while(next_permutation(vec.begin(), vec.end()));
    }
    return answer;
}