#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> nums{2,7,11,15};
int target = 9;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> data;
        int length = nums.size();
        vector<int> res;
        for(int i = 0; i < length; i++){
            if(data.find(target - nums[i]) != data.end()){
                res.push_back(data[target - nums[i]]);
                res.push_back(i);
                break;
            }
            data[nums[i]] = i;
        }
        return res;
    }
};

int main(){
    Solution A;
    auto res = A.twoSum(nums,target);
    for(int val : res){
        cout << val << " ";
    }
}