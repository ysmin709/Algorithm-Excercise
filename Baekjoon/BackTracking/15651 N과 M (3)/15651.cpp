#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[10] = { 0, };
bool visited[10] = { 0, };

void dfs(int x) {
    if (x == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        arr[x] = i;
        dfs(x + 1);
        visited[i] = false;
    }
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    cin >> n >> m;

    dfs(0);
}