#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> nums = {3,1};

class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size() - 1;
        if(!length) return 0;
        int ans = 0;
        int i = 0, j, k, fi = nums[i] + i;
        while(fi < length) {
            for(j = i + 1, k = i; j <= fi; ++j) {
                if(j + nums[j] > k + nums[k])
                    k = j;
            }
            i = k;
            fi = nums[i] + i;
            ++ans;
        }
        return ++ans;
    }
};

int main(){
    Solution A;
    int ans = A.jump(nums);
    cout << ans << endl;
}