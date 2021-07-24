#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0); // 탈락자가 없는 상황을 고려해서 vector를 0, 0으로 구성한다.
    vector<string> useWord; // 사용된 단어 리스트
    
    for (int i = 0; i < words.size(); i++) {
        if (i == 0) useWord.push_back(words[i]); // 처음은 그냥 넣는다
        else {
            auto it = find(useWord.begin(), useWord.end(), words[i]);
            if (it != useWord.end() // 현재 단어가 이미 사용된 단어인지 체크
                || useWord[useWord.size()-1][useWord[useWord.size()-1].size()-1] != words[i][0]) { // 마지막으로 사용됐던 단어의 끝자리와 현재 단어의 첫째 자리가 같은지 체크
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                break;
            }
            useWord.push_back(words[i]);
        }
    }
    
    return answer;
}