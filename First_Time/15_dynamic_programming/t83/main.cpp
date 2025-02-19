#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> nums = {100,0,0,100,0,0,0};

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> ans_num;
        int length = nums.size();
        if(length == 1) return nums[0];
        int rob_last = nums[0], not_rob_last = 0;
        int next_rob_last, next_not_rob_last;
        int ans = rob_last;
        for(int i = 1; i < length; i++){
            next_rob_last = nums[i] + not_rob_last;
            next_not_rob_last = max(rob_last, not_rob_last);
            ans = max(ans, max(next_rob_last, next_not_rob_last));
            rob_last = next_rob_last;
            not_rob_last = next_not_rob_last;
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