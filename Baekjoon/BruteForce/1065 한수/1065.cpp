#include <iostream>
#include <string>
using namespace std;

int answer = 0;

void check (int n) {
    string temp = to_string(n);

    if (temp.size() <= 2) answer++; // 1자리 수와 2자리 수는 무조건 등차수열이다.
    else { // 1000은 등차수열이 아니기 때문에 3자리수만 체크한다.
        if (temp[0] - temp[1] == temp[1] - temp[2]) answer++;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) check(i);

    cout << answer << endl;
}