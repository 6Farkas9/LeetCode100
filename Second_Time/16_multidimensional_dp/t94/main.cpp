#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

string text1 = "abc";
string text2 = "def";

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n +1, 0));
        int i, j, s_i, s_j;
        for(i = 1, s_i = 0; i<= m; ++i, ++s_i){
            for(j = 1, s_j = 0; j <= n; ++j, ++s_j){
                if(text1[s_i] == text2[s_j]){
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
                }
                else{
                    dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution A;
    auto ans = A.longestCommonSubsequence(text1, text2);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}