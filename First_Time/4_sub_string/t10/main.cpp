#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nums{-1,6,-2,4,3};
int k = 5;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pre_sum; //前缀和，前缀数量
        int res = 0;
        pre_sum[0] = 1;
        int length = nums.size();
        int current_pre = 0;
        for(int i=0; i<length;i++){
            current_pre += nums[i];
            if(pre_sum.find(current_pre - k) != pre_sum.end()){
                res += pre_sum[current_pre - k];
            }
            pre_sum[current_pre]++;
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.subarraySum(nums,k);
    cout << res << endl;
}