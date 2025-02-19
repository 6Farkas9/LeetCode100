#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

string text1 = "intention";
string text2 = "execution";

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i - 1] == text2[j - 1])    dp[i][j] = dp[i - 1][j - 1] + 1;
                else    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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