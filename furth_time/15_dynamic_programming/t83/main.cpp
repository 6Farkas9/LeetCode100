#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> nums = {2,7,9,3,1};

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) return nums[0];
        int last_y = nums[0], last_n = 0, ans = nums[0];
        for(int i = 1; i < length; ++i) {
            last_y = last_n + nums[i];
            last_n = ans;
            ans = max(last_y, last_n);
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.rob(nums);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}