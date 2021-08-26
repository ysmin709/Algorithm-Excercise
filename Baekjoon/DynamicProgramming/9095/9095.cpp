#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        vector<int> v(11, 0); // temp는 11보다 작기 때문에 11까지 생성
        v[1] = 1; // v[4]를 구하기 위해서 v[1], v[2], v[3]까지는 지정한다.
        v[2] = 2;
        v[3] = 4;
        for (int j = 4; j <= temp; j++) v[j] = v[j-1] + v[j-2] + v[j-3];

        cout << v[temp] << endl;
    }
}