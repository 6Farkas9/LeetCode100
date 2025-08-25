#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {1,3,5,7};
int target = 0;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, mid;
        while(i <= j) {
            mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    }
};

int main(){
    Solution A;
    int res =  A.searchInsert(nums, target);
    cout << res << endl;
}