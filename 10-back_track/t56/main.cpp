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
        int length = nums.size();
        subsetsRecursion(nums, 0, length);
        return this->ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> current;
    void subsetsRecursion(vector<int>& nums, int i, int & length){
        if(i == length){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        subsetsRecursion(nums, i+1, length);
        current.pop_back();
        subsetsRecursion(nums, i+1, length);
    }
};

int main(){
    Solution A;
    vector<vector<int>> res = A.subsets(nums);
    cout << res.size() << endl;
    for(auto len : res){
        for(auto val : len){
            cout << val << " ";
        }
        cout << endl;
    }
}