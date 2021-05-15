#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 100

void DFS(int x, int y);
bool compare(int a, int b);

int n1, n2;
char arr[MAX][MAX];
bool visit[MAX][MAX];
int house_cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector <int> vec;

int main() {
    cin >> n1 >> n2;
	
	for (int i = 0; i < n2; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n1; j++) arr[i][j] = temp[j];
	}

	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			if (arr[i][j] == '.' && visit[i][j] == false) {
				house_cnt = 0;
				DFS(i, j);
				vec.push_back(house_cnt);
			}
		}
	}

	sort(vec.begin(), vec.end(), compare);
	cout << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}

void DFS(int x, int y) {
	house_cnt++;
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n2 || ny < 0 || ny >= n1) continue;
		if (arr[nx][ny] == '.' && visit[nx][ny] == false) DFS(nx, ny);
	}
}

bool compare(int a, int b) {
    return a > b;
}