#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {  
    int i = citations.size();
    
    sort(citations.begin(), citations.end());

    while (i > 0) {
        for (int j = 0; j < citations.size(); j++) {
            int above = 0, below = 0;
            if (citations[j] >= i) {
                above = citations.size() - j;
                below = j + 1;
                if (above >= i && below <= i) return i;
            }
        }
        i--;
    }
}