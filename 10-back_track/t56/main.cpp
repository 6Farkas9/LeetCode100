#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> nums = {1,2,3};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length = nums.size() - 1;
        vector<vector<int>> ans;
        vector<int> current_ans;
        recursion(nums, 0, length, ans, current_ans);
        return ans;
    }
private:
    void recursion(vector<int>& nums, int start, int end, vector<vector<int>> &ans, vector<int> &current_ans){
        if(start > end){
            ans.push_back(current_ans);
            return;
        }
        recursion(nums, start + 1, end, ans, current_ans);
        current_ans.push_back(nums[start]);
        recursion(nums, start + 1, end, ans, current_ans);
        current_ans.pop_back();
    }
};

int main(){
    Solution A;
    vector<vector<int>> res = A.subsets(nums);
    cout << res.size() << endl;
    for(auto len : res){
        cout << "[";
        for(auto val : len){
            cout << val << " ";
        }
        cout << "]" << endl;
    }
}