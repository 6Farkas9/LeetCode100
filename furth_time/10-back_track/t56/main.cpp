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
        vector<vector<int>> ans;
        vector<int> temp;
        int length = nums.size(); 
        recursion(0, nums, temp, ans, length);
        return ans;
    }
private:
    void recursion(int i, vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans, int &lenght) {
        if(i >= lenght) {
            ans.emplace_back(temp);
            return;
        }
        recursion(i + 1, nums, temp, ans, lenght);
        temp.emplace_back(nums[i]);
        recursion(i + 1, nums, temp, ans, lenght);
        temp.pop_back();
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