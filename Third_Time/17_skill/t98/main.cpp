#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {1,2,0};
                    // 1 0 0 0 1 1 2 2 2 2
                    // 0 1 0 0 1 1 2 2 2 2
                    // 0 0 1 0 1 1 2 2 2 2
                    // 0 0 0 1 1 1 2 2 2 2


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int p0 = 0, p1 = 0;
        for(int i = 0; i < length; ++i){
            if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                if(p0 < p1){
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
            else if(nums[i] == 1){
                swap(nums[i], nums[p1]);
                ++p1;
            }
        }
    }
};

int main(){
    Solution A;
    A.sortColors(nums);

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