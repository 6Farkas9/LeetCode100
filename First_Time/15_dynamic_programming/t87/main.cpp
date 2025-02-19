#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {0,8,4,12,2};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0, length = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < length; i++){
            if(nums[i] > dp[ans]){
                dp.push_back(nums[i]);
                ans++;
            }
            else{
                int left = 0, right = ans;
                while(left < right){
                    int mid = (left + right) / 2;
                    if(dp[mid] == nums[i]){
                        left = mid;
                        break;
                    }
                    else if(dp[mid] < nums[i]){
                        left = mid + 1;
                    }
                    else{
                        right = mid;
                    }
                }
                dp[left] = nums[i];
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