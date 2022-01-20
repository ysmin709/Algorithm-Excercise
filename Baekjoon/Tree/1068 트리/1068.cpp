#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, answer = 0;
    scanf("%d", &n);

    vector<vector<int>> arr(51, vector<int>());

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        
        if (temp == -1) continue;
        arr[temp].push_back(i);
    }

    int del;
    scanf("%d", &del);

    for (int i = 0; i < n; i++) {
        if (n == del) continue;
        if (arr[i].size() == 0) answer++;
        else {
            for ()
        }
    }

    printf("%d", answer);
}