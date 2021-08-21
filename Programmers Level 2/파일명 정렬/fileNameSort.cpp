#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (string a, string b) {
    string Ahead = "", Bhead = "";
    string Anumber = "", Bnumber = "";
    
    int i = 0;
    while (!(a[i] >= '0' && a[i] <= '9')) { Ahead += tolower(a[i]); i++; } // a의 Head 추출
    while (a[i] >= '0' && a[i] <= '9') { Anumber += a[i]; i++; } // a의 Number 추출
    
    i = 0;
    while (!(b[i] >= '0' && b[i] <= '9')) { Bhead += tolower(b[i]); i++; } // b의 Head 추출
    while (b[i] >= '0' && b[i] <= '9') { Bnumber += b[i]; i++; } // b의 Number 추출
    
    if (Ahead != Bhead) return Ahead < Bhead; // Head가 다르다면 Head 기준으로 정렬
    else return stoi(Anumber) < stoi(Bnumber); // Head가 같다면 숫자 기준으로 정렬
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}