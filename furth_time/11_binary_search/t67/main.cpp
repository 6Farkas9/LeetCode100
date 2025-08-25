#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {4,5,6,7,0,1,2};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size() - 1;
        int i = 0, j = length, mid;
        while(i <= j) {
            mid = (i + j) / 2;
            if(nums[mid] > nums[length])    i = mid + 1;
            else    j = mid - 1;
        }
        return nums[i];
    }
};

int main(){
    Solution A;
    int res =  A.findMin(nums);
    cout << res << endl;
}