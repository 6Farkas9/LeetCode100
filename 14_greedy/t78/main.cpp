#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> nums = {2,3,1,1,4};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        int far_pos = 0;
        for(int i = 0; i < length; i++){
            if(i <= far_pos){
                far_pos = max(far_pos, i + nums[i]);
                if(far_pos >= length - 1)   return true;
            }
            else    break;
        }
        return false;
    }
};

int main(){
    Solution A;
    auto ans = A.canJump(nums);
    cout << ans << endl;
}