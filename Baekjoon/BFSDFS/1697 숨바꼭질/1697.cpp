#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100001] = { 0, };
queue<int> q;

int BFS(int n) {
    q.push(n);
    visited[n] = 1;

    while(!q.empty()) {
        n = q.front();
        q.pop();

        if (n == k) break;
        if (n-1 >= 0 && !visited[n-1]) { q.push(n-1); visited[n-1] = visited[n] + 1; } // 1칸 돌아갈 때
        if (n+1 <= 100000 && !visited[n+1]) { q.push(n + 1); visited[n+1] = visited[n] + 1; } // 1칸 앞으로 갔을 때
        if (n*2 <= 100000 && !visited[n*2]) { q.push(n * 2); visited[n*2] = visited[n] + 1; } // 2배 앞으로 갔을 때
    }
    return visited[n]-1;
}

int main() {
    cin >> n >> k;

    cout << BFS(n) << endl;
}