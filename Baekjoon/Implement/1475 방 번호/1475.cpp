#include <iostream>
#include <algorithm> 
using namespace std;
 
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
            
    int arr[10] = {0};
 
    while(true) {
        arr[n % 10]++;
        if (n / 10 == 0) break;
        n /= 10;    
    }
 
    int num = 0;
    for(int i = 0; i < 10; i++){
        if(i != 9 && i != 6) num = max(num, arr[i]);
    }
    
    cout << max(num, (arr[6] + arr[9] + 1) / 2);
    return 0;    
}