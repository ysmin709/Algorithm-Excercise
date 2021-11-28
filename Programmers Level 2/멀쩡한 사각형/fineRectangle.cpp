using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

long long solution(int w,int h) {
    long long answer = 1;
    
    // 동일하게 잘리는 패턴 = w와 h의 최소공배수
    // 잘리는 개수 = 전체 개수 + w와 h의 최대공약수 - (가로 + 세로)
    answer = ((long long)w * h) + gcd(w, h) - w - h;
    
    return answer;
}