#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> answer;
    vector<int> tmp;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        answer.push_back(temp);
    }

    for (int i = 0; i < t; i++) {
        tmp = answer;
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                if (tmp[j+1] < 3) answer[j]--;
                else if (tmp[j+1] > 7) answer[j]--;
                else if (tmp[j+1] >= 4 && tmp[j+1] <= 7) answer[j]++;
                else if (tmp[j+1] == 3) continue;
            }
            else if (j == n-1) {
                if (tmp[j-1] < 3) answer[j]--;
                else if (tmp[j-1] > 7) answer[j]--;
                else if (tmp[j-1] >= 4 && tmp[j-1] <= 7) answer[j]++;
                else if (tmp[j-1] == 3) continue;                
            }
            else {
                if (tmp[j-1] + tmp[j+1] < 3) answer[j]--;
                else if (tmp[j-1] + tmp[j+1] > 7) answer[j]--;
                else if (tmp[j-1] + tmp[j+1] >= 4 && tmp[j-1] + tmp[j+1] <= 7) answer[j]++;
                else if (tmp[j-1] + tmp[j+1] == 3) continue;
            }
            if (answer[j] > 9) answer[j] = 9;
            else if (answer[j] < 0) answer[j] = 0;
        }
    }

    for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
}