#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, w, L, answer = 0;
    cin >> n >> w >> L;

    int dist = w;
    deque<int> dq(n);
    deque<pair<int, int>> temp;

    for (int i = 0; i < n; i++) cin >> dq[i];

    while (!dq.empty() || !temp.empty()) {
        for (int i = 0; i < temp.size(); i++) temp[i].second++;

        if (temp[0].second == dist) { // 트럭이 다리를 건넜을 때
            w++;
            L += temp[0].first;
            temp.pop_front();
        }

        if (!dq.empty() && w > 0 && L >= dq.front()) { // 남은 트럭이 다리에 올라갈 수 있을 때
            temp.push_back(make_pair(dq.front(), 0));
            w--;
            L -= dq.front();
            dq.pop_front();
        }

        answer++;
    }

    cout << answer << "\n";
}