#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int last_max = nums[0];
        int ans = last_max;
        for(int i = 1; i < length; ++i) {
            int temp = nums[i] + max(0, last_max);
            ans = max(ans, temp);
            last_max = temp;
        }
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.maxSubArray(nums);
    cout << res << endl;
}