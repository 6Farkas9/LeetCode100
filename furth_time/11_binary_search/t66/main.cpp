#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {3, 1};
int target = 3;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size() - 1;
        int i = 0, j = length, mid;
        while(i <= j) {
            mid = (i + j) / 2;
            if(nums[mid] > nums[length])    i = mid + 1;
            else j = mid - 1;
        }
        if(target <= nums[length]) j = length;
        else {
            j = i - 1;
            i = 0;
        }
        while(i <= j) {
            mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution A;
    int res =  A.search(nums, target);
    cout << res << endl;
}