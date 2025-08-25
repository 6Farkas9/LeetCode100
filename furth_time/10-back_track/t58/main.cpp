#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> candidates = {2,3,6,7};
int target = 7;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end(), [&](const int &a, const int &b){
        //     return a > b;
        // });
        vector<vector<int>> ans;
        vector<int> temp;
        int length = candidates.size();
        recursion(0, candidates, target, temp, ans, length);
        return ans;
    }
private:
    void recursion(int i, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int &lenght) {
        if(i >= lenght) {
            if(!target) {
                ans.emplace_back(temp);
            }
            return;
        }
        int max_num = target / candidates[i];
        recursion(i + 1, candidates, target, temp, ans, lenght);
        for(int j = 1; j <= max_num; ++j) {
            temp.push_back(candidates[i]);
            recursion(i + 1, candidates, target - j * candidates[i], temp, ans, lenght);
        }
        for(int i = 1; i <= max_num; ++i) {
            temp.pop_back();
        }
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