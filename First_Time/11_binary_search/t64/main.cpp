#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {};
int target = 6;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int length = nums.size() - 1;
        int has_target = searchPos(nums, target, 0, length);
        if(has_target == -1)    return ans;
        int left_edge = has_target - 1;
        int right_edge = has_target + 1;
        while(true){
            has_target = searchPos(nums, target, 0, left_edge);
            if(has_target == -1) break;
            left_edge = has_target - 1;
        }
        ans[0] = left_edge + 1;
        while(true){
            has_target = searchPos(nums, target, right_edge, length);
            if(has_target == -1) break;
            right_edge = has_target + 1;
        }
        ans[1] = right_edge - 1;
        return ans;
    }
private:
    int searchPos(vector<int>& nums, int target, int i, int j){
        while(i <= j){
            int mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution A;
    auto res =  A.searchRange(nums, target);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
}