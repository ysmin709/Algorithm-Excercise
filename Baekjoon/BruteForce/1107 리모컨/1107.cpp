#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int target, n, crash, answer;
    cin >> target >> n;
    vector<bool> vec(10, true);

    for (int i = 0; i < n; i++) { // 고장난 버튼 체크
        cin >> crash;
        vec[crash] = false;
    }

    string str = to_string(target);
    answer = abs(target - 100); // 100번 채널에서 시작하므로 -100을 해준다.

    for (int i = 0; i <= 1000000; i++) {
        bool check = true;

        for (int j = 0; j < to_string(i).size(); j++) {
            if (!vec[to_string(i)[j] - '0']) { check = false; break; } // 고장난 버튼이면 break
        }

        if (check) { // 고장나지 않은 버튼일 때
            int temp = abs(target - i) + to_string(i).size();
            answer = min(answer, temp);
        }
    }

    cout << answer << endl;
}