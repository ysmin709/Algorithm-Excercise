using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;
    
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a > 0 && b > 0) {
        answer++;
        if (a % 2 == 1 && a+1 == b) return answer;
        else {
            if (a % 2 == 1) a = a / 2 + 1;
            else a /= 2;
            if (b % 2 == 1) b = b / 2 + 1;
            else b /= 2;
        }
    }
}