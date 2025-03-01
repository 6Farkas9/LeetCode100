#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> nums = {100,0,0,100,0,0,0};

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= length; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[length];
    }
};

int main(){
    Solution A;
    auto ans = A.rob(nums);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}