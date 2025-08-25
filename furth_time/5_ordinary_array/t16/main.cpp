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
        vector<int> ans(length);
        int l = 1, r = 1;
        int i = 0, j = length - 1;
        while(i < j){
            l = ans[i] = l * nums[i];
            r = ans[j] = r * nums[j];
            ++i;
            --j;
        }
        while(j > 0) {
            ans[i] = ans[i + 1] * l;
            ans[j] = ans[j - 1] * r;
            l = l * nums[i];
            r = r * nums[j];
            ++i;
            --j;
        }
        ans[0] = r, ans[length - 1] = l;
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