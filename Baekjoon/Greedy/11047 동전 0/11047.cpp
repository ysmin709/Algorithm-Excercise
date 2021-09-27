#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, c, answer = 0;
    cin >> n >> k;
    vector <int> coin;

    for (int i = 0; i < n; i++) {
        cin >> c;
        coin.push_back(c);
    }

    int i = n-1; // 제일 큰 수부터 체크
    while (k > 0 && i >= 0) {
        if (coin[i] <= k) { // 효율을 높이기 위해 k보다 작으면 k를 coin[i]로 나눈 값만큼 coin[i]에 곱해서 k를 뺀다.
            int temp = k / coin[i];
            k -= coin[i] * temp;
            answer += temp;
        }
        i--;
    }

    cout << answer << endl;
}