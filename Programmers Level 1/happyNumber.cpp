#include <iostream>
#include <vector>

using namespace std;

void happy(int n);
 
vector<int> v;
int main() {
    int n;
    cin >> n;
    happy(n);
}

void happy(int n) {
        int temp = n;
        int result = 0;

        if (n == 1) {
            cout << "HAPPY" << endl;
            return;
        }
        for(int i=0; i<v.size(); i++) {
            if (n == v[i]) {
                    cout << "UNHAPPY" << endl;
                    return;
            }
        }
       v.push_back(n);

        while (temp) {
            result += (temp % 10)*(temp % 10);
            temp /= 10;
        }
        happy(result);
}