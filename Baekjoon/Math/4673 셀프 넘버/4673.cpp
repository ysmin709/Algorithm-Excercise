#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[10001];

    for (int i = 1; i <= 10000; i++) {
        string temp = to_string(i);
        int save = i;

        for (int j = 0; j < temp.size(); j++) save += (temp[j] - '0');    
        if (save <= 10000) arr[save] = 1;
    }

    for (int i = 1; i <= 10000; i++) {
        if (arr[i] != 1) cout << i << endl;
    }
}