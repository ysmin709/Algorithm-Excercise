#include <iostream>
#include <string>

using namespace std;

bool checkParenthesis(string str);

int main() {
    string str;
    cin >> str;

    cout << checkParenthesis(str) << endl;
}

bool checkParenthesis(string str) {
    int Lcnt = 0, Rcnt = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') Lcnt++;
        else Rcnt++;
        if (Lcnt < Rcnt) return false;
    }
    if (Lcnt == Rcnt) return true;
    else return false;
}