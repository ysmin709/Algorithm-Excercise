#include <iostream>
#include <vector>

using namespace std;

int** genMagicSquare(int n);

int main(void) {
    int n;
    cin >> n;

    if (!(n%2)) return 1;

    int **sq = genMagicSquare(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << sq[i][j] << " ";
        cout << endl;
    }
}

int** genMagicSquare(int n) {
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) arr[i] = new int[n];
    int cnt = 1;
    int i = 0, j = n / 2;

    while(cnt <= n*n) {
        arr[i][j] = cnt;
        i--; j++; cnt++;
        if (i < 0) i = n-1;
        if (j > n-1) j = 0;
        if (arr[i][j]) { i+=2; j--; }
        if (i == n) i = 0;
        if (i == n+1) i = 1;
        if (j < 0) j = n-1;
    }

    return arr;
}
