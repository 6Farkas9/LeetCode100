#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {3,1,2};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size() - 1;
        int i = 0,j = length;
        int mid;
        while(i < j){
            mid = (i + j) / 2;
            if(nums[mid] < nums[length])  j = mid;
            else i = mid + 1;
        }
        return nums[mid];
    }
};

int main(){
    Solution A;
    int res =  A.findMin(nums);
    cout << res << endl;
}