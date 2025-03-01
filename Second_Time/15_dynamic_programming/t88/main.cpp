#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {2,3,-2,4};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int ans = nums[0];
        int _max = nums[0], _min = nums[0];
        for(int i = 1; i < length; ++i){
            int with_max = nums[i] * _max;
            int with_min = nums[i] * _min;
            _max = max(nums[i], max(with_max, with_min));
            _min = min(nums[i], min(with_max, with_min));
            ans = max(ans, _max);
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