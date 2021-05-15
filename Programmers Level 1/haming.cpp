#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int hamming(int n);

int main() {
   int t, n;
   cin >> t;
   for (int i = 0; i < t; i++) {
      cin >> n;
      cout << hamming(n) << endl;
   }
}

int hamming(int n) {
   int temp = 0;
   int arr[1350] = { 0 };

   for (int i = 0; i < 13; i++) {
      for (int j = 0; j < 19; j++) {
         for (int k = 0; k < 29; k++) {
            if (pow(2, k)*pow(3, j)*pow(5, i) <= 398580750) {
               arr[temp] = pow(2, k)*pow(3, j)*pow(5, i);
               temp++;
            }
         }
      }
   }
   sort(arr, arr + 1350);
   return arr[n - 1];
}