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
        vector<vector<int>> ans;
        recursion(nums, ans, length, 0);
        return ans;
    }
private:
    void recursion(vector<int> &nums, vector<vector<int>> &ans, int &length, int start){
        if(start == length){
            ans.push_back(nums);
            return;
        }
        for(int i = start; i <= length; ++i){
            swap(nums[start], nums[i]);
            recursion(nums, ans, length, start + 1);
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