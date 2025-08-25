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
        vector<vector<int>> ans;
        int length = nums.size();
        recursion(0, nums, ans, length);
        return ans;
    }
private:
    void recursion(int i, vector<int>& nums, vector<vector<int>> &ans, int &length) {
        if(i >= length) {
            ans.emplace_back(nums);
            return;
        }
        recursion(i + 1, nums, ans, length);
        for(int j = i + 1; j < length; ++j) {
            swap(nums[i], nums[j]);
            recursion(i + 1, nums, ans, length);
            swap(nums[i], nums[j]);
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