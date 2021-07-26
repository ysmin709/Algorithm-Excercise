#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    vector<int> arr2(arr.begin(), arr.end()); // arr를 복사
    
    int max = 0; // 최소공배수의 기준이 되는 값
    
    for (int i = 0; i < arr.size(); i++) if (max < arr[i]) max = arr[i]; // 초기 max 최신화
    
    while (true) {
        int cnt = 0; // 모두 같은 수인지 체크하는 변수
        for (int i = 0; i < arr2.size(); i++) {
            if (max < arr2[i]) max = arr2[i]; // 원소가 max보다 크면 max 최신화
            else if (max > arr2[i]) {
                arr2[i] += arr[i]; // 해당하는 배수를 더해준다
                if (max < arr2[i]) max = arr2[i]; // 증가된 값이 max보다 크면 max 최신화
            }
            else cnt++; // max와 원소의 값이 같을 대 cnt 증가
        }
        if (cnt == arr.size()) return max; // 모든 원소의 값이 같으면 return
    }
}