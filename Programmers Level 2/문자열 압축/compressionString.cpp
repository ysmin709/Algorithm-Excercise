#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 10000; // min을 구해야 하기 때문에 불가능한 값으로 설정
    
    if (s.size() == 1) return 1; // string 사이즈가 1이면 1 리턴
    
    for (int i = 1; i <= s.size() / 2; i++) { // string 사이즈를 / 2 값까지만 자르는 의미가 있음
        if (s.size() / i < 1) break;
        
        string temp = s.substr(0, i); // 초기 n단위로 자른 string
        int cnt = 1;
        int leng = 0;
        
        for (int j = i; j <= s.size(); j++) {
            string tmp = "";
            
            for (int k = 0; k < i; k++){ // 범위를 벗어났을 때를 처리하기 위해 substr을 사용하지 않고 for문을 사용
                if (j+k >= s.size()) break;
                tmp += s[j+k];
            }
            
            if (temp == tmp) cnt++; // 비교 대상이 같으면 cnt 증가
            else {
                if (cnt > 1) { // 중복된 부분이 끝났을 때 cnt가 2 이상일 때
                    string num = to_string(cnt);
                    leng += temp.size() + num.size();
                }
                else leng += temp.size();
                temp = tmp;
                cnt = 1;
            }
            j += i - 1;
        }
        
        if (cnt > 1) {
            string num = to_string(cnt);
            leng += temp.size() + num.size();
        }
        else leng += temp.size();

        answer = min(answer, leng);
    }
    
    return answer;
}