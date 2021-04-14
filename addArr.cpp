#include <iostream>

using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    int *arr1 = new int[n1*n2];
    int *arr2 = new int[n1*n2];

    for (int i = 0; i < n1*n2; i++) {
        int temp;
        cin >> temp;
        arr1[i] = temp;
    }
    
    for (int i = 0; i < n1*n2; i++) {
        int temp;
        cin >> temp;
        arr2[i] = temp;
    }

    for (int i = 0; i < n1*n2; i++) arr1[i] += arr2[i];

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) cout << arr1[i*n2 + j] << " ";
        cout << endl;
    }

    delete[] arr1;
    delete[] arr2;
}