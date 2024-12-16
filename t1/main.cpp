#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> nums{2,7,11,15};
int target = 9;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> un_nums;
        int length = nums.size();
        vector<int> res;
        for(int i=0; i<length; i++){
            int this_one = nums[i];
            auto another_one = un_nums.find(target - this_one);
            if(another_one != un_nums.end()){
                res.push_back(i);
                res.push_back(another_one->second);
                break;
            }
            un_nums[nums[i]] = i;
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