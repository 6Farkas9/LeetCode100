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
        int ans_length = 1;
        string ans = s.substr(0, 1);
        vector<vector<bool>> dp(length, vector<bool>(length, true));
        for(int k = 1; k < length; k++){
            for(int j = k; j < length; j++){
                int i = j - k;
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                if(dp[i][j] && j - i + 1 > ans_length){
                    ans_length = j - i + 1;
                    ans = s.substr(i, ans_length);
                }    
            }
        }
        return ans;
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