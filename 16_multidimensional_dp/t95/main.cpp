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
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) dp[i][0] = i;
        for(int j = 1; j <= n; j++) dp[0][j] = j;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int temp = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = word1[i-1] == word2[j-1] ? min(dp[i-1][j-1], temp) : min(dp[i-1][j-1]+1, temp);
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