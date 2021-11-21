#include <cstdio>
#include <queue>
#include <string>
#include <functional>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int, vector<int>, less<int>> delete_pq;

        for (int j = 0; j < n; j++) {
            string temp;
            scanf("%s", &temp);
            if (temp[0] == 'I') {
                temp.erase(0, 2);
                int num = stoi(temp);
            }
            else {
                if (pq.empty()) continue;
                if (temp[2] == '1') {
                    
                }
                else pq.pop();
            }
        }
    }
}