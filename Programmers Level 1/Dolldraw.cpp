#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> temp;
    
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i]-1] != 0) {
                temp.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
        if (temp.size() > 1) {
            if (temp[temp.size()-1] == temp[temp.size()-2]) {
                temp.pop_back(); temp.pop_back();
                answer += 2;
            }
        }
    }
    
    return answer;
}