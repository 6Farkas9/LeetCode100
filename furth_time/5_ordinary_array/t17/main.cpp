#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{1, 1};

// 0 1 2 3  4 5 6 7 8 9
// 3 5 6 0

// nums[j] > 0
// nums[j] -> nums[j] - 1
//     -> nums[j] - 1 < length
// nums[nums[j] - 1] != nums[j] 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        int ans = 1;
        for(int i = 0; i < length; ++i) {
            int j = i;
            while(nums[j] > 0 && nums[j] <= length && nums[nums[j] - 1] != nums[j]) {
                swap(nums[j], nums[nums[j] - 1]);
            }
        }
        for(; ans <= length && nums[ans - 1] == ans; ++ans) {}
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.firstMissingPositive(nums);
    cout << res << endl;
}