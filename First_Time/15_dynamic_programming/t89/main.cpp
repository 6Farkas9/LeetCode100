#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {1,5,11,5};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) return false;
        int sum = 0 ,max_num = INT_MIN;
        for(int i = 0; i < length; i++){
            sum += nums[i];
            max_num = max(max_num, nums[i]);
        }
        if(sum % 2 == 1)    return false;
        int target = sum / 2;
        if(max_num > target)    return false;
        if(max_num == target)   return true;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int i = 0; i < length; i++){
            int num = nums[i];
            for(int j = target; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

int main(){
    Solution A;
    auto ans = A.canPartition(nums);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}