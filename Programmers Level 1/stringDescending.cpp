#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> v;
    
    for (int i = 0; i < s.size(); i++) v.push_back(s[i]);
    sort(v.begin(), v.end());
    for (int i = v.size()-1; i >= 0; i--) answer += v[i];
    
    return answer;
}