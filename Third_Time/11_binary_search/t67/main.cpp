#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {2,1};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size() - 1;
        int i = 0, j = length, mid = 0;
        if(nums[0] > nums[length]){
            while(i <= j){
                mid = (i + j) / 2;
                if(!mid || nums[mid] > nums[length])    i = mid + 1;
                else if(nums[mid] < nums[mid - 1])   break; 
                else    j = mid - 1;
            }
        }
        return nums[mid];
    }
};

int main(){
    Solution A;
    int res =  A.findMin(nums);
    cout << res << endl;
}