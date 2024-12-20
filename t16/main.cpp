#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums{-1,1,0,-3,3};
//               1,2,12,4
//                 j  i
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> res(length,1);
        int left = 1,right = 1;
        int i,j;
        for(i = 0,j = length - 1; i < length; i++,j--){
            if(i < j){
                left *= nums[i];
                right *= nums[j];
                res[i] = left;
                res[j] = right;
            }
            else{
                if(j == 0){
                    res[i] = left;
                    res[j] = right;
                }
                else{
                    res[i] = left * res[i+1];
                    res[j] = right * res[j-1];
                    left *= nums[i];
                    right *= nums[j];
                }
            }
        }
        return res;
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