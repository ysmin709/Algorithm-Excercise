#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int max = 0, tmp = 0;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            matrix[i][j] = input;
        }
    }

    for (int i = 0; i < n; i++) max += matrix[i][i];
    
    int i = 0, j = 0;
    for (int a = 0; a < n-1; a++) {
        for (int b = 0; b < n; b++) {
            if (i >= n) i = 0;
            j++;
            if (j >= n) j = 0;
            tmp += matrix[i][j];
            i++;
        }
        if (max < tmp) max = tmp;
        tmp = 0;
        i++; j++;
    }
    j = 1;

    for (int i = 0; i < n; i++) {
        for (int j = n-1; j <= 0; j++) tmp += matrix[i][j];
    }
    if (max < tmp) max = tmp;
    else tmp = 0;

    i = 0; j = 1;
    for (int a = 0; a < n-1; a++) {
        for (int b = 0; b < n; b++) {
            if (i >= n) i = 0;
            j--;
            if (j < 0) j = 0;
            tmp += matrix[i][j];
            i++;
        }
        if (max < tmp) max = tmp;
        tmp = 0;
        i++; j++;
    }

    cout << max << endl;
}