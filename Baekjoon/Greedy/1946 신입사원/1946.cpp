#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int cnt = 1;
        vector<pair<int, int>> vec(n, pair<int, int>(0, 0));

        for (int j = 0; j < n; j++) scanf("%d %d", &vec[j].first, &vec[j].second);
        
        sort(vec.begin(), vec.end()); // first를 기준으로 오름차순 정렬

        int big = vec[0].second; // 인덱스 0은 무조건 성공
        for (int j = 1; j < vec.size(); j++) {
            if (vec[j].second < big) { // 자신보다 first 우선순위가 높은 상대보다 second 우선순위가 높으면 cnt++
                cnt++;
                big = vec[j].second;
            }
        }

        printf("%d\n", cnt);
    }
}