#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> candidates = {2};
int target = 1;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->current_sum = 0;
        int length =  candidates.size();
        this->target = target;
        recursion(candidates, 0, length);
        return this->ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> current;
    int current_sum;
    int target;
    void recursion(vector<int>& candidates, int i, int & length){
        if(i >= length) return;
        this->current.push_back(candidates[i]);
        this->current_sum += candidates[i];
        if(this->current_sum == this->target){
            this->ans.push_back(this->current);
        }
        else if(this->current_sum < this->target){
            recursion(candidates, i, length);
            for(int j = 1; i+j < length; j++)
                recursion(candidates, i+j, length);
        }
        this->current.pop_back();
        this->current_sum -= candidates[i];
        if(!this->current.size() && i+1 < length)
            recursion(candidates, i+1, length);
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