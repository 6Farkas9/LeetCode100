#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {2,0,2,1,1,0};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], length = nums.size(), count = 1;
        for(int i = 1; i < length; ++i) {
            if(nums[i] != ans)
                --count;
            else
                ++count;
            if(!count) {
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.majorityElement(nums);

    cout << ans << endl;
}