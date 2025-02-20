#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums{1,2,3,4};
//               1,2,12,4
//                 j  i
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> ans(length, 1);
        int ans_i = 1, ans_j = 1;
        for(int i = 0, j = length - 1; i < length && j >= 0; ++i, --j){
            if(i < j){
                ans_i = ans_i * nums[i];
                ans_j = ans_j * nums[j];
                ans[i] = ans_i;
                ans[j] = ans_j;
            }
            else if(j == 0){
                ans[i] = ans_i;
                ans[j] = ans_j;
            }
            else{
                ans[i] = ans_i * ans[i + 1];
                ans[j] = ans_j * ans[j - 1];
                ans_i = ans_i * nums[i];
                ans_j = ans_j * nums[j];
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    vector<int> res = A.productExceptSelf(nums);
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;
}