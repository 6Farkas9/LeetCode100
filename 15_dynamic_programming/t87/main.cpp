#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {15,16,17,18,6,7,8,0,1,2,3,4,5};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp;
        int i, ans = 0;
        dp.push_back(nums[0]);
        for(i = 1; i < length; ++i){
            if(nums[i] > dp[ans]){
                dp.push_back(nums[i]);
                ++ans;
            }
            else if(nums[i] < dp[ans]){
                int left = 0, right = ans;
                while(left <= right){
                    int mid = (left + right) / 2;
                    if(dp[mid] == nums[i]){
                        left = mid;
                        break;
                    }
                    else if(dp[mid] > nums[i])  right = mid - 1;
                    else    left = mid + 1;
                }
                dp[left] = nums[i];
            }
            for(int j = 0; j <= ans; ++j)   cout << dp[j] << " ";
            cout << endl;
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