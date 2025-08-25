#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> nums = {2,3,1,1,4};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size() - 1;
        int i = 0, j, k, fi = nums[i] + i;
        while(fi < length) {
            k = i;
            for(j = i + 1; j <= fi; ++j) {
                if(j + nums[j] > k + nums[k])
                    k = j;
            }
            if(k == i)  return false;
            i = k;
            fi = i + nums[i];
        }
        return true;
    }
};

int main(){
    Solution A;
    auto ans = A.canJump(nums);
    cout << ans << endl;
}