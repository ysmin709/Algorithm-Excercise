#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, "");
    vector<vector<int>> temp1(n, vector<int>(n, 0));
    vector<vector<int>> temp2(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        int j = n-1;
        while(arr1[i] > 1) {
            temp1[i][j] = arr1[i] % 2;
            arr1[i] /= 2;
            j--;
        }
        temp1[i][j] = arr1[i];
    }
    for (int i = 0; i < n; i++) {
        int j = n-1;
        while(arr2[i] > 1) {
            temp2[i][j] = arr2[i] % 2;
            arr2[i] /= 2;
            j--;
        }
        temp2[i][j] = arr1[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp1[i][j] || temp2[i][j]) answer[i] += "#";
            else answer[i] += " ";
        }
    }
    
    return answer;
}