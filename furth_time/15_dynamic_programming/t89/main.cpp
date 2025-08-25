#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {1,2,5};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto &num : nums)
            target += num;
        if(target % 2 != 0)    return false;
        target /= 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto &num : nums) {
            for(int i = target; i >= 0; --i) {
                if(dp[i] && i + num <= target)
                    dp[i + num] = true;
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