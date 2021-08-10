#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0; i < skill_trees.size(); i++) {
        int cnt = 0; // 해당되는 스킬의 인덱스 위치 확인 변수
        for (int j = 0; j < skill_trees[i].size(); j++) {
            auto it = find(skill.begin(), skill.end(), skill_trees[i][j]);
            if (it != skill.end()) { // skill에 해당됐을 때
                if (cnt == it - skill.begin()) { cnt++; } // 선행 스킬인지 확인
                else break; // 선행 스킬이 아니므로 다음 스킬트리로 넘어감
            }
            if (j == skill_trees[i].size()-1) answer++; // 선행 스킬을 잘 지켰다면
        }
    }
    return answer;
}