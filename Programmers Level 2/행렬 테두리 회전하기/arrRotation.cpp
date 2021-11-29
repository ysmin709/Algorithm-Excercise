#include <string>
#include <vector>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(rows, vector<int>(columns, 0));
    
    int num = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = num;
            num++;
        }
    }
    
    for (int i = 0; i < queries.size(); i++) {
        int num = arr[queries[i][0]-1][queries[i][1]-1], small = 10001, temp;
        
        for (int j = queries[i][1]; j < queries[i][3]; j++) { // 테두리 중 윗부분 회전
            temp = arr[queries[i][0]-1][j];
            small = min(small, temp);
            arr[queries[i][0]-1][j] = num;
            num = temp;
        }
        for (int j = queries[i][0]; j < queries[i][2]; j++) { // 오른쪽 회전
            temp = arr[j][queries[i][3]-1];
            small = min(small, temp);
            arr[j][queries[i][3]-1] = num;
            num = temp;
        }
        for (int j = queries[i][3]-2; j >= queries[i][1]-1; j--) { // 아래 회전
            temp = arr[queries[i][2]-1][j];
            small = min(small, temp);
            arr[queries[i][2]-1][j] = num;
            num = temp;
        }
        for (int j = queries[i][2]-2; j >= queries[i][0]-1; j--) { // 왼쪽 회전
            temp = arr[j][queries[i][1]-1];
            small = min(small, temp);
            arr[j][queries[i][1]-1] = num;
            num = temp;
        }
        
        answer.push_back(small);
    }
    
    return answer;
}