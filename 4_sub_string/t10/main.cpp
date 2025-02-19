#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nums{1,1,1};
int k = 2;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int length = nums.size();
        if(!length) return 0;
        unordered_map<int,int> pre_sum;
        int ans = 0;
        int last_sum = 0;
        pre_sum[0] = 1;
        for(int i = 0; i < length; ++i){
            if(pre_sum.find(last_sum - (k - nums[i])) != pre_sum.end()){
                ans += pre_sum[last_sum - (k - nums[i])];
            }
            last_sum += nums[i];
            pre_sum[last_sum]++;
        }
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.subarraySum(nums,k);
    cout << res << endl;
}