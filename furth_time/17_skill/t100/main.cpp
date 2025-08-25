#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {1,3,4,2,2};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, j = 0;
        do{
            i = nums[i];
            j = nums[nums[j]];
        }while(i != j);
        j = 0;
        while(i != j){
            i = nums[i];
            j = nums[j];
        }
        return i;
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