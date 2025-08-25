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
        unordered_set<string> word_set;
        for(string &word : wordDict)
            word_set.insert(word);
        int length = s.size(), i, j;
        vector<bool> dp(length + 1, false);
        dp[0] = true;
        for(i = 1; i <= length; ++i) {
            for(j = 0; j < i; ++j) {
                if(dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[length];
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