#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int numRows = 5;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; ++i){
            ans.push_back(vector<int>(i + 1, 1));
            for(int j = 1; j < i; ++j){
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.generate(numRows);
    for(auto val : ans){
        for(auto vval : val){
            cout << vval << " ";
        }
        cout << endl;
    }
}