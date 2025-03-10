#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> coins = {1, 2, 5};
int amount = 11;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int length = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < length; j++){
                if(coins[j] <= i)   dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(){
    Solution A;
    auto ans = A.coinChange(coins, amount);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}