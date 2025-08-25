#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> nums = {1,2,3,2};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        int i, j = length - 1, k;
        while(j > 0 && nums[j - 1] >= nums[j]) --j; 
        if(j > 0) {
            i = j - 1, k = length - 1;
            while(nums[k] <= nums[i])   --k;
            swap(nums[i], nums[k]);
        }
        reverse(nums.begin() + j, nums.end());
    }
};

int main(){
    Solution A;
    A.nextPermutation(nums);

    // cout << ans << endl;

    for(auto val : nums){
        cout << val << " ";
    }
    cout << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}