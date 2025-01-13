#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<vector<int>> grid = {
    {1,2,3},
    {4,5,6}
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(grid[0]);
        for(int i = 1; i < n; i++){
            dp[i] += dp[i - 1];
        }
        for(int i = 1; i < m; i++){
            dp[0] += grid[i][0];
            for(int j = 1; j < n; j++){
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        return dp[n - 1];
    }
};

int main(){
    Solution A;
    auto ans = A.minPathSum(grid);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}