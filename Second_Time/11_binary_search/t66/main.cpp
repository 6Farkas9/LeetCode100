#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums = {1};
int target = 0;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size() - 1;
        int i = 0, j = length, mid;
        if(nums[0] > nums[length]){
            while(i <= j){
                mid = (i + j) / 2;
                if(nums[mid] == target) return mid;
                if(nums[mid] > nums[mid + 1])   break;
                else if(nums[mid] >= nums[0])   i = mid + 1;
                else    j = mid - 1;
            }
            if(target >= nums[0]){
                i = 0;
                j = mid;
            }
            else{
                i = mid + 1;
                j = length;
            }
        }
        while(i <= j){
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