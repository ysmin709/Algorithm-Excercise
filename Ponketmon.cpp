#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    
    int n = nums.size() / 2;
    int temp = 0;
    int m = -1;
    
    for (int i = 0; i < nums.size(); i++) {
        if (m != nums[i]) {
            temp++;
            m = nums[i];
        }
        if (n == temp) return temp;
    }
    return temp;
}