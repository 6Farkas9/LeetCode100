#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {0,1,0,3,2,3};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size(), i, l, r, m, ans = 0;
        vector<int> dp(length);
        dp[0] = nums[0];
        for(i = 1; i < length; ++i) {
            if(nums[i] > dp[ans]) {
                dp[++ans] = nums[i];
            }
            else {
                l = 0, r = ans;
                while(l <= r) {
                    m = (l + r) / 2;
                    if(dp[m] >= nums[i])    r = m - 1;
                    else l = m + 1;
                }
                dp[l] = nums[i];
            }
        }
        return ans + 1;
    }
};

int main(){
    Solution A;
    auto ans = A.lengthOfLIS(nums);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}