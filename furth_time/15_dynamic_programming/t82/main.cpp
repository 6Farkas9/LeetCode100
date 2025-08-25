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
        int i, j, k;
        for(i = 0; i < numRows; ++i) {
            ans.emplace_back(vector<int>(i + 1, 1));
            k = i - 1;
            for(int j = 1; j < i; ++j) {
                ans[i][j] = ans[k][j - 1] + ans[k][j];
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