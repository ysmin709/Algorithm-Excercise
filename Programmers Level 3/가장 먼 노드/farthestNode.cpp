#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> arr(n + 1, vector<int>());
    
    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i][0];
        int y = edge[i][1];
        
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    vector<int> vec(n + 1, -1); // 1번 노드와의 거리를 저장하는 벡터
    queue<int> q;
    
    vec[1] = 0; // 시작 지점 거리 0으로 설정
    q.push(1);
    
    while (!q.empty()) { // bfs 사용
        int x = q.front();
        q.pop();
        
        for (int i = 0; i < arr[x].size(); i++) {
            if (vec[arr[x][i]] == -1) { // -1이 visited와 같은 역할을 한다.
                q.push(arr[x][i]);
                vec[arr[x][i]] = vec[x] + 1;
            }
        }
    }
    
    sort(vec.rbegin(), vec.rend()); // 거리 정보를 내림차순으로 정렬
    
    int max = vec[0]; // 0번 인덱스가 가장 큰 값이므로 max를 0번 인덱스로 설정
    for (int i = 0; i < n; i++) {
        if (vec[i] == max) answer++;
        else break;
    }
    
    return answer;
}