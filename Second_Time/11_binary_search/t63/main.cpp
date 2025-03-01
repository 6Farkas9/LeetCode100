#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {1,3,5,6};
int target = 7;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int j = nums.size() - 1;
        int i = 0, mid;
        while(i <= j){
            mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid - 1;
            else    i = mid + 1;
        }
        return i;
    }
};

int main(){
    Solution A;
    int res =  A.searchInsert(nums, target);
    cout << res << endl;
}