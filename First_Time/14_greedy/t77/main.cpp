#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> prices = {7};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int min_price = INT_MAX, ans = 0;
        for(int i = 0; i < length; i++){
            if(prices[i] < min_price){
                min_price = prices[i];
            }
            if(prices[i] > min_price && prices[i] - min_price > ans){
                ans = prices[i] - min_price;
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