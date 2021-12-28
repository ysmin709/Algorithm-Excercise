#include <string>
#include <map>
#include <cmath>
using namespace std;

int solution(string word) {
    int answer = 0;
    
    map<char, int> m;
    m['A'] = 0; m['E'] = 1; m['I'] = 2; m['O'] = 3; m['U'] = 4;
    
    for (int i = 0; i < word.size(); i++) {
		answer++;
		for (int j = 0; j < m[word[i]]; j++) {
			for (int k = 4; k >= i; k--) answer += pow(5, 4 - k);
		}
	}
    
    return answer;
}