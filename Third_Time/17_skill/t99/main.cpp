#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> nums = {};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size() - 1;
        int i = length - 1;
        while(i >= 0 && nums[i] >= nums[i + 1]) --i;
        if(i >= 0){
            int j = length;
            while(j >= 0 && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
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