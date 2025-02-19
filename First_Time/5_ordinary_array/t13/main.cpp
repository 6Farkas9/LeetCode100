#include <iostream>
#include <vector>

#include <limits.h>

using namespace std;

vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp_len = nums[0];
        int res = temp_len;
        int n_len = nums.size();
        for(int i=1; i<n_len; i++){
            temp_len = nums[i] + max(0 , temp_len);
            if(temp_len > res){
                res = temp_len;
            }
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.maxSubArray(nums);
    cout << res << endl;
}