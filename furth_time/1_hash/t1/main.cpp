#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nums = {2,7,11,15};
int target = 9;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> num_hash;
        int i = 0;
        for(int &num : nums) {
            if(num_hash.find(target - num) != num_hash.end() && 
               i != num_hash[target - num]) {
                ans.emplace_back(num_hash[target - num]);
                ans.emplace_back(i);
                break;
            }
            num_hash[num] = i++;
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res = A.twoSum(nums,target);
    for(int val : res){
        cout << val << " ";
    }
}