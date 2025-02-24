#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> candidates = {2,3,6,7};
int target = 7;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int length = candidates.size();
        this->current_sum = 0;
        recursion(candidates, 0, length, target);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> current_ans;
    int current_sum;
    void recursion(vector<int>& candidates, int start, int &end, int &target){
        if(this->current_sum > target)  return;
        if(this->current_sum == target){
            this->ans.push_back(this->current_ans);
            return;
        }
        if(start == end)    return;
        int num = (target - this->current_sum) / candidates[start];
        for(int i = num; i > 0; --i){
            this->current_ans.push_back(candidates[start]);
            this->current_sum += candidates[start];
        }
        for(int i = num; i > 0; --i){
            recursion(candidates, start + 1, end, target);
            this->current_ans.pop_back();
            this->current_sum -= candidates[start];
        }
        recursion(candidates, start + 1, end, target);
    }
};

int main(){
    Solution A;
    vector<vector<int>> res = A.combinationSum(candidates,target);
    cout << res.size() << endl;
    for(auto len : res){
        for(auto val : len){
            cout << val << " ";
        }
        cout << endl;
    }
}