#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n;
int arr[1001];
bool visited[1001];
bool check[1001];

void dfs(int node) {
    visited[node] = true;
    check[node] = true;

    if (check[arr[node]]) return;
    if (!visited[arr[node]]) dfs(arr[node]);

    check[node] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int answer = 0;

    cin >> t;

    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        memset(check, false, sizeof(check));
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> arr[i];

        for (int i = 1; i <= n; i++) {
            if (!visited[arr[i]]) {
                dfs(arr[i]);
                answer++;
            }
        }

        cout << answer << endl;
        answer = 0;
    }
}