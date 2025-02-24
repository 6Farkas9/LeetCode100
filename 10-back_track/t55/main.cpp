#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> nums = {1,2,3};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int length = nums.size() - 1;
        premuteRecursion(nums, 0, length);
        return this->ans;
    }
private:
    vector<vector<int>> ans;
    void premuteRecursion(vector<int>& nums, int start, int end){
        if(start == end){
            this->ans.push_back(nums);
            return;
        }
        for(int i = start; i <= end; ++i){
            swap(nums[start], nums[i]);
            premuteRecursion(nums, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
};

int main(){
    Solution A;
    vector<vector<int>> res = A.permute(nums);
    cout << res.size() << endl;
    for(auto len : res){
        for(auto val : len){
            cout << val << " ";
        }
        cout << endl;
    }
}