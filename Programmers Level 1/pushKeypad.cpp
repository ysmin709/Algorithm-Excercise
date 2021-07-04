#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int Left = 3;
    bool LeftM = false;
    int Right = 3;
    bool RightM = false;
    int middle[4] = { 2, 5, 8, 0 };
    
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            if (numbers[i] == 1) Left = 0;
            else if (numbers[i] == 4) Left = 1;
            else Left = 2;
            LeftM = false;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            if (numbers[i] == 3) Right = 0;
            else if (numbers[i] == 6) Right = 1;
            else Right = 2;
            RightM = false;
        }
        else {
            int loc = 0;
            int distanceL = 0, distanceR = 0;
            for (int j = 0; j < 4; j++) {
                if (middle[j] == numbers[i]) { loc = j; break; }
            }
            if (LeftM == false) distanceL = abs(Left - loc) + 1;
            else distanceL = abs(Left - loc);
            if (RightM == false) distanceR = abs(Right - loc) + 1;
            else distanceR = abs(Right - loc);
            
            if (distanceL < distanceR) { answer += 'L'; LeftM = true; Left = loc; }
            else if (distanceR < distanceL) { answer += 'R'; RightM = true; Right = loc; }
            else {
                if (hand == "left") { answer += 'L'; LeftM = true; Left = loc; }
                else { answer += 'R'; RightM = true; Right = loc; }
            }
        }
    }
    
    return answer;
}