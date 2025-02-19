#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {3,1,3,4,2};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(nums[slow] != nums[fast]);
        fast = 0;
        while(nums[fast] != nums[slow]){
            fast = nums[fast];
            slow = nums[slow];
        }
        return nums[fast];
    }
};

int main(){
    Solution A;
    auto ans = A.findDuplicate(nums);

    cout << ans << endl;

    // for(auto val : nums){
    //     cout << val << " ";
    // }
    // cout << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}