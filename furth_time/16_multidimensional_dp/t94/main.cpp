#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

string text1 = "bsbininm";
string text2 = "jmjkbkjkv";

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        bool found = false;
        for(int i = 0; i < l1; ++i) {
            if(found)   dp[i][0] = 1;
            else {
                if(text1[i] == text2[0]) {
                    found = true;
                    dp[i][0] = 1;
                }
            }
        }
        for(int j = 0, found = false; j < l2; ++j) {
            if(found)   dp[0][j] = 1;
            else {
                if(text1[0] == text2[j]) {
                    found = true;
                    dp[0][j] = 1;
                }
            }
        }
        for(int i = 1; i < l1; ++i) {
            for(int j = 1; j < l2; ++j) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1 - 1][l2 - 1];
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