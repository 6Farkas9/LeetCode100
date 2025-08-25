#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> coins = {1, 2, 5};
int amount = 11;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        int min_coin = INT_MAX, i, j, coin_num = coins.size();
        sort(coins.begin(), coins.end());
        unordered_set<int> coin_set;
        for(auto & coin : coins) {
            min_coin = min(min_coin, coin);
            coin_set.insert(coin);
        }
        dp[0] = 0;
        for(i = min_coin; i <= amount; ++i) {
            if(coin_set.find(i) != coin_set.end()) {
                dp[i] = 1;
                continue;
            }  
            for(j = 0; j < coin_num && coins[j] <= i; ++j) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
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