#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        map<char, int> m;
        string temp;
        cin >> temp;
        
        bool check = true;
        
        char now;
        for (int j = 0; j < temp.size(); j++) {
            if (m[temp[j]] == 0) {
                now = temp[j];
                m[temp[j]]++;
            }
            else if (temp[j] == now) continue;
            else {
                check = false;
                break;
            }
        }
        
        if (check) answer++;
    }
    
    cout << answer << endl;
}