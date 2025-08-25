#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {1};
int target = 1;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int length = nums.size() - 1;
        int i = 0, j = length, mid;
        bool found = false;
        while(i <= j) {
            mid = (i + j) / 2;
            if(nums[mid] == target) found = true;
            if(nums[mid] >= target) j = mid - 1;
            else i = mid + 1;
        }
        if(!found)  return ans;
        ans[0] = i;
        j = length;
        while(i <= j) {
            mid = (i + j) / 2;
            if(nums[mid] <= target) i = mid + 1;
            else j = mid - 1;
        }
        ans[1] = j;
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.searchRange(nums, target);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
}