#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> prices = {7,1,5,3,6,4};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int ans = 0;
        int buy_in = INT_MAX;
        for(int i = 0; i < length; ++i) {
            if(prices[i] < buy_in) {
                buy_in = prices[i];
            }
            else {
                ans = max(ans, prices[i] - buy_in);
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.maxProfit(prices);
    cout << ans << endl;
}