#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>
#include <stack>

using namespace std;

string s = "(((())))";
// 0 1 2 3 4 5 6 7 8 9

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, c = 0;
        int length = s.size();
        vector<int> dp(length + 1, -1);
        for(int i = 0; i < length; ++i) {
            if(s[i] == '(') {
                dp[++c] = i;
            }
            else {
                if(c == 0 || s[dp[c]] == ')') {
                    dp[++c] = i;
                }
                else {
                    ans = max(ans, i - dp[--c]);
                }
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