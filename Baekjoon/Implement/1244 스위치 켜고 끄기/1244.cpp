#include <iostream>
#include <vector>
using namespace std;

int arr_size;
vector<int> vec(100);

void man(int idx) { // 자신의 위치 배수 확인
	int i = idx;

	while (i < arr_size) {
		if (vec[i]) vec[i] = 0;
		else vec[i] = 1;

		i += idx + 1;
	}
}

void woman(int idx) { // 펠린드롬 확인
	int i = idx - 1, j = idx + 1;

	if (vec[idx]) vec[idx] = 0;
	else vec[idx] = 1;

	while (i >= 0 && j < arr_size) {
		if (vec[i] == vec[j]) { // 펠린드롬 이면 값을 바꾼다
			if (vec[i]) { vec[i] = 0; vec[j] = 0; }
			else { vec[i] = 1; vec[j] = 1; }
			i--; j++;
		}
		else break;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    cin >> arr_size;
	for (int i = 0; i < arr_size; i++) cin >> vec[i];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, loc;
		cin >> s >> loc;

		if (s == 1) man(loc - 1);
		else woman(loc - 1);
	}

	for (int i = 1; i <= arr_size; i++) {
		cout << vec[i - 1] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}