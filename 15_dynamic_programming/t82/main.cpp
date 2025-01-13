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
        ans.push_back(vector<int>{1});
        if(numRows == 1)    return ans;
        ans.push_back(vector<int>{1,1});
        if(numRows == 2)    return ans;
        vector<int> temp;
        for(int i = 2; i < numRows; i++){
            temp.resize(i + 1,1);
            int edge = i - 1;
            for(int j = 1; j <= edge; j++){
                temp[j] = ans[edge][j-1] + ans[edge][j];
            }
            ans.push_back(temp);
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