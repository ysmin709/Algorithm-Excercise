#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    string str, answer = "", temp = "";
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '<') {
            if (temp.size() > 0) {
                reverse(temp.begin(), temp.end());
                answer += temp;
                temp = "";
            }

            answer += str[i];
            i++;

            while (str[i] != '>') {
                answer += str[i];
                i++;
            }
            answer += '>';
        }
        else if (str[i] == ' ') {
            reverse(temp.begin(), temp.end());
            answer += temp;
            temp = "";
            answer += " ";
        }
        else temp += str[i];
    }

    if (temp.size() > 0) {
        reverse(temp.begin(), temp.end());
        answer += temp;
    }

    cout << answer << "\n";
}