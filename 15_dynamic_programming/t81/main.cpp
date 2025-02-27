#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int n = 10;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        vector<int> dp(n);
        dp[0] = 1, dp[1] = 2;
        for(int i = 2; i < n; ++i)  dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n-1];
    }
};

int main(){
    Solution A;
    auto ans = A.climbStairs(n);
    cout << ans << endl;
}