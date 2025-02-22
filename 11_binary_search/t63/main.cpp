#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {1,3,5,6};
int target = 0;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            int mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        nums.insert(nums.begin() + i,target);
        return i;
    }
};

int main(){
    Solution A;
    int res =  A.searchInsert(nums, target);
    cout << res << endl;
}