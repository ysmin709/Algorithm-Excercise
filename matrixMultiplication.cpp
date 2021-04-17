#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int **arr1 = new int*[b];
    int **arr2 = new int*[c];

    for (int i = 0; i < a; i++) arr1[i] = new int[b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int temp;
            cin >> temp;
            arr1[i][j] = temp;
        }
    }
    for (int i = 0; i < b; i++) arr2[i] = new int[c];
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c; j++) {
            int temp;
            cin >> temp;
            arr2[i][j] = temp;
        }
    }

    int result;
    for (int i = 0 ; i < a; i++) {
        for (int j = 0; j < c; j++) {
            result = 0;
            for (int k = 0; k < b; k++) result += arr1[i][k] * arr2[k][j];
            cout << result << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < b; i++) delete [] arr1[i];
    for (int i = 0; i < c; i++) delete [] arr2[i];
    delete [] arr1;
    delete [] arr2;
}