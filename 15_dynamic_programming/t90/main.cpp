#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

string s = ")()())";
// 0 1 2 3 4 5 6 7 8 9

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        int ans = 0;
        vector<int> dp(length, 0);
        for(int i = 0; i < length; i++){
            if(s[i] == ')'){
                int j = i - 1;
                if(j >= 0){
                    if(dp[j] == 0 && s[j] == '('){
                        if(j - 1 >= 0)  dp[i] = dp[j - 1] + 2;
                        else    dp[i] = 2;
                    }
                    else if(dp[j] == 0){
                        dp[i] = 0;
                    }
                    else{
                        int k = j - dp[j];
                        if(k >= 0){
                            if(s[k] == '('){
                                if(k - 1 >= 0)  dp[i] = 2 + dp[j] + dp[k - 1];
                                else    dp[i] = dp[i] = 2 + dp[j];
                            }
                        }
                    }
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.longestValidParentheses(s);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}