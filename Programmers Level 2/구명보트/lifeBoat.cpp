#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.rbegin(), people.rend()); // 내림차순 정렬
    
    for (int i = 0; i < people.size(); i++) {
        if (limit == people[i]) { answer++; continue; } // 한 사람 무게가 limit과 같다면 바로 처리
        
        
        int j = i+1; // 현재 가장 몸무게가 많이 나가는 사람 다음부터 체크하는 변수
        int max = 0; // 이진탐색을 진행하면서 최대한 limit에 맞추기 위한 변수
        int idx = j; // 어디까지 탐색했는지 저장하는 변수
        
        while (j <= people.size()-1) { // people 크기만큼
            if (max == people[j]) { people.erase(people.begin()+j); break; } // max가 현재 사람 몸무게와 같다면 더 이상 탐색해도 같기 때문에 종료
            if (people[i] + people[j] > limit) {
                idx = j; // 어디까지 탐색했는지 저장
                j = j + (people.size() - 1 - j) / 2 + 1; // 이진 탐색 값 증가
            }
            else if (people[i] + people[j] < limit) {
                max = people[j]; // 최대한 limit에 맞추기 위해 저장
                j = j - (j - idx) / 2; // 이진 탐색 값 감소
            }
            else { people.erase(people.begin()+j); break; } // limit과 딱 맞아 떨어질 때 종료
        }
        answer++;
    }
    
    return answer;
}