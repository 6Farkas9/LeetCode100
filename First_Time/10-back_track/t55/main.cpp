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
        permute_recursion(nums, 0, nums.size() - 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void permute_recursion(vector<int>& nums, int i, int j){
        if(i == j){
            vector<int> temp = nums;
            ans.push_back(temp);
            return;
        }
        int k = i;
        while(k <= j){
            swap(nums[i], nums[k]);
            for(int val : nums) cout << val << " ";
            cout << ";";
            permute_recursion(nums, i + 1, j);
            swap(nums[i], nums[k]);
            for(int val : nums) cout << val << " ";
            cout << endl;
            k++;
        }
    }
};

int main(){
    Solution A;
    vector<vector<int>> res = A.permute(nums);
//     cout << res.size() << endl;
//     for(auto len : res){
//         for(auto val : len){
//             cout << val << " ";
//         }
//         cout << endl;
//     }
}