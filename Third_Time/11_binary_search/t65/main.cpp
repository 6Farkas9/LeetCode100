#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {5,7,7,8,8,10};
int target = 6;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size() - 1;
        int i, j, mid;
        vector<int> ans(2, -1);
        if(length == -1)    return ans;
        int start = 0, end = length;
        if(nums[start] != target){
            i = 0, j = length;
            while(i <= j){
                cout << i << "," << j << endl;
                mid = (i + j) / 2;
                if(mid > 0 && nums[mid - 1] != target && nums[mid] == target){
                    start = mid;
                    break;
                }
                else if(nums[mid] >= target)    j = mid - 1;
                else    i = mid + 1;
            }
            if(i > j)   return ans;
        }
        if(nums[end] != target){
            i = 0, j = length;
            while(i <= j){
                cout << i << "," << j << endl;
                mid = (i + j) / 2;
                if(mid < length && nums[mid + 1] != target && nums[mid] == target){
                    end = mid;
                    break;
                }
                else if(nums[mid] <= target)    i = mid + 1;
                else    j = mid - 1;
            }
            if(i > j)   return ans;
        }
        ans[0] = start, ans[1] = end;
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.searchRange(nums, target);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
}