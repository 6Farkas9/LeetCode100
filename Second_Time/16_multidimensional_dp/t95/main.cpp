#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

string word1 = "";
string word2 = "";

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int i, j, s_i, s_j;
        for(i = 1; i <= m; ++i) dp[i][0] = i;
        for(i = 1; i <= n; ++i) dp[0][i] = i;
        for(i = 1, s_i = 0; i <= m; ++i, ++s_i){
            for(j = 1, s_j = 0; j <= n; ++j, ++s_j){
                if(word1[s_i] == word2[s_j])    dp[i][j] = dp[s_i][s_j];
                else    dp[i][j] = min(dp[s_i][s_j], min(dp[s_i][j], dp[i][s_j])) + 1;
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution A;
    auto ans = A.minDistance(word1, word2);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}