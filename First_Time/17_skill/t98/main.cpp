#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {2,0,0,0,1,1,1,2,2,2};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, i;
        while(l < r){
            while(l < r && nums[l] == 0)    l++;
            while(l < r && nums[r] == 2)    r--;
            if(l < r){
                if(nums[l] == nums[r]){
                    i = l + 1;
                    while(i < r && nums[i] == 1)    i++;
                    if(i < r && nums[i] == 0){
                        swap(nums[l++], nums[i]);
                    }
                    else if(i < r){
                        swap(nums[i], nums[r--]);
                    }
                    else{
                        break;
                    }
                }
                else if(nums[l] == 1){
                    swap(nums[l++], nums[r]);
                }
                else if(nums[r] == 1){
                    swap(nums[l], nums[r--]);
                }
                else{
                    swap(nums[l++], nums[r--]);
                }
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