#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> vec;
    
    if (cacheSize == 0) return cities.size() * 5;
    
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
    }
    
    for (int i = 0; i < cities.size(); i++) {
        bool hit = false;
        int idx;
        
        for (int j = 0; j < vec.size(); j++) {
            if (cities[i] == vec[j]) { hit = true; idx = j; break; }
        }
        
        if (hit) {
            vec.push_back(vec[idx]);
            vec.erase(vec.begin()+idx);
            answer++;
        }
        else {
            if (vec.size() == cacheSize) {
                vec.erase(vec.begin());
                vec.push_back(cities[i]);
            }
            else vec.push_back(cities[i]);
            answer += 5;
        }
    }
    
    return answer;
}