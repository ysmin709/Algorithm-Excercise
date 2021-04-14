#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Intersection (vector<int> arrA, vector<int> arrB);
void Union (vector<int> arrA, vector<int> arrB);
void Minus (vector<int> arrA, vector<int> arrB);

int main() {
    vector<int> arrA;
    vector<int> arrB;
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int temp;
        cin >> temp;
        arrA.push_back(temp);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int temp;
        cin >> temp;
        arrB.push_back(temp);
    }
    Intersection(arrA, arrB);
    Union(arrA, arrB);
    Minus(arrA, arrB);
}

void Intersection (vector<int> arrA, vector<int> arrB) {
    vector<int>::iterator it;
    vector<int> InterArr;
    for (int i = 0; i < arrA.size(); i++) {
        it = find(arrB.begin(), arrB.end(), arrA[i]);
        if (it == arrB.end()) continue;
        else InterArr.push_back(*it);
    }
    sort(InterArr.begin(), InterArr.end());
    cout << InterArr.size() << " ";
    for (int i = 0; i < InterArr.size(); i++) cout << InterArr[i] << " ";
    cout << endl;
}

void Union (vector<int> arrA, vector<int> arrB) {
    vector<int>::iterator it;
    for (int i = 0; i < arrB.size(); i++) {
        it = find(arrA.begin(), arrA.end(), arrB[i]);
        if (it == arrA.end()) arrA.push_back(arrB[i]);
        else continue;
    }
    sort(arrA.begin(), arrA.end());
    cout << arrA.size() << " ";
    for (int i = 0; i < arrA.size(); i++) cout << arrA[i] << " ";
    cout << endl;
}

void Minus(vector<int> arrA, vector<int> arrB) {
    vector<int>::iterator it;
    for (int i = 0; i < arrB.size(); i++) {
        it = find(arrA.begin(), arrA.end(), arrB[i]);
        if (it == arrA.end()) continue;
        else arrA.erase(it);
    }
    sort(arrA.begin(), arrA.end());
    cout << arrA.size() << " ";
    for (int i = 0; i < arrA.size(); i++) cout << arrA[i] << " ";
    cout << endl;
}