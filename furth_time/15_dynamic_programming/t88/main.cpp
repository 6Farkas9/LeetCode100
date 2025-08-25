#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {-2,0,-1};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int last_max = nums[0], last_min = nums[0], m, n, ans = nums[0];
        for(int i = 1; i < length; ++i) {
            m = nums[i] * last_max;
            n = nums[i] * last_min;
            last_max = max(nums[i], max(m, n));
            last_min = min(nums[i], min(m, n));
            ans = max(ans, last_max);
        }
        return ans;
    }   
};

int main(){
    Solution A;
    auto ans = A.maxProduct(nums);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}