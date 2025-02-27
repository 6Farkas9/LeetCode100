#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {3,3,3,4,5};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size();
        int sum = 0, _max = INT_MIN;
        if(length == 1) return false;
        cout << "1" << endl;
        for(int i = 0; i < length; ++i){
            sum += nums[i];
            _max = max(_max, nums[i]);
        }
        if(sum % 2 != 0)    return false;
        cout << "2" << endl;
        int target = sum / 2;
        if(_max > target)   return false;
        cout << "3" << endl;
        if(_max == target)  return true;
        cout << "4" << endl;
        // vector<bool> dp(target + 1, false);
        // dp[0] = true;
        // for(int i = 0; i < length; ++i){
        //     int num = nums[i];
        //     for(int j = target; j >= num; --j){
        //         dp[j] = dp[j] || dp[j - num];
        //     }
        // }
        // return dp[target];

        // int length = nums.size();
        // if(length == 1) return false;
        // cout << "1" << endl;
        // int sum = 0 ,max_num = INT_MIN;
        // for(int i = 0; i < length; i++){
        //     sum += nums[i];
        //     max_num = max(max_num, nums[i]);
        // }
        // if(sum % 2 == 1)    return false;
        // cout << "2" << endl;
        // int target = sum / 2;
        // if(max_num > target)    return false;
        // cout << "3" << endl;
        // if(max_num == target)   return true;
        // cout << "4" << endl;
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