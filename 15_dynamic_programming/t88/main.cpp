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
        long ans = nums[0];
        long min_last = nums[0], max_last = nums[0];
        int length = nums.size();
        for(int i = 1; i < length; i++){
            long temp_min = min_last, temp_max = max_last;
            max_last = max((long)nums[i], max(nums[i] * temp_max, nums[i] * temp_min));
            min_last = min((long)nums[i], min(nums[i] * temp_max, nums[i] * temp_min));
            if(min_last < INT_MIN){
                min_last = nums[i];
            }
            ans = max(ans, max_last);
        }
        return (int)ans;
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