#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

string s = "applepenapple";
vector<string> wordDict = {"apple", "pen"};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = s.size();
        unordered_set<string> word_set;
        for(string & str : wordDict)    word_set.insert(str);
        vector<vector<bool>> judge(length, vector<bool>(length, false));
        int i, j, k;
        for(k = 0; k < length; ++k){
            for(j = k; j < length; ++j){
                i = j - k;
                judge[i][j] = word_set.find(s.substr(i, k + 1)) != word_set.end();
            }
        }
        vector<bool> dp(length, false);
        for(j = 0; j < length; ++j){
            if(judge[0][j]) dp[j] = true;
            else{
                for(i = 0; i < j; ++i){
                    dp[j] = dp[j] || (dp[i] && judge[i+1][j]);
                    if(dp[j])   break;
                }
            }
        }
        return dp[length - 1];
    }
};

int main(){
    Solution A;
    auto ans = A.wordBreak(s, wordDict);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}