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
        int i = 0,j = length;
        int mid,k;
        while(i <= j){
            mid = (i + j) / 2;
            cout << i << "," << j << "," << mid << endl;
            if(nums[mid] == target) return mid;
            if(mid + 1 > length || nums[mid] > nums[mid+1]) break;
            if(nums[mid] > nums[length])    i = mid + 1;
            else    j = mid - 1;
        }
        k = mid;
        i = 0;
        j = k;
        while(i <= j){
            mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target)  j = mid - 1;
            else    i = mid + 1;
        }
        i = k+1;
        j = length;
        while(i <= j){
            mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target)  j = mid - 1;
            else    i = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution A;
    int res =  A.search(nums, target);
    cout << res << endl;
}