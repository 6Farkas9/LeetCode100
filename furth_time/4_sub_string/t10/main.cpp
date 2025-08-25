#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nums{1,2,3};
int k = 3;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> pre_sum;
        pre_sum[0] = 1;
        int psum = 0;
        for(int &num : nums) {
            ans += pre_sum[psum - k + num];
            psum += num;
            ++pre_sum[psum];
        }
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.subarraySum(nums,k);
    cout << res << endl;
}