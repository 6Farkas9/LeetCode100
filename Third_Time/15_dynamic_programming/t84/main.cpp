#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;
int n = 12;

class Solution {
public:
    int numSquares(int n) {
        double sqn = sqrt(n);
        if(int(sqn) == sqn) return 1;
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; ++i){
            sqn = sqrt(i);
            int int_sqn = (sqn);
            if(int_sqn == sqn)    dp[i] = 1;
            else{
                int temp = INT_MAX;
                for(int j = 1; j <= int_sqn; ++j){
                    temp = min(temp, dp[i - j * j]);
                }
                dp[i] = temp + 1;
            }
        }
        return dp[n];
    }
};

int main(){
    Solution A;
    auto ans = A.numSquares(n);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}