#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) { // value 기준으로 오름차순 정렬
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string temp;

    map<string, int> m;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        m[temp] = i + 1; // map에 이름과 순서로 저장
    }

    vector<pair<string, int>> vec(m.begin(), m.end()); // sort 하기 위해 map의 정보를 vector로 가져온다.
    sort(vec.begin(), vec.end(), cmp); // 오름차순 정렬
    
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (temp[0] >= '0' && temp[0] <= '9') cout << vec[stoi(temp)-1].first << "\n"; // 입력이 숫자면 n번째 이름을 출력
        else cout << m[temp] << "\n"; // 입력이 이름이면 해당 번호 출력
    }
}