#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> prices = {7,1,5,3,6,4};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int length = prices.size();
        int buyin = INT_MAX;
        for(int i = 0; i < length; ++i){
            if(prices[i] < buyin)   buyin = prices[i];
            else if(prices[i] > buyin){
                ans = max(ans, prices[i] - buyin);
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