#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

string s = "babad";

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int start = 0, sub_length = 1,i, j, k;
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        for(i = 0; i < length; ++i) dp[i][i] = true;
        for(k = 1; k < length; ++k){
            for(j = k; j < length; ++j){
                i = j - k;
                dp[i][j] = (k == 1 || dp[i + 1][j - 1]) && s[i] == s[j];
                if(dp[i][j] && sub_length < k + 1){
                    start = i;
                    sub_length = k + 1;
                }
            }
        }
        return s.substr(start, sub_length);
    }
};

int main(){
    Solution A;
    auto ans = A.longestPalindrome(s);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}