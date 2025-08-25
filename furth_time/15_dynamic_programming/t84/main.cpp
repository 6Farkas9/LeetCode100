#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;
int n = 12;

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares{1};
        int i, j;
        for(i = 4; i <= n; ++i) {
            if(judge(i))
                squares.emplace_back(i);
        }
        int length = squares.size();
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for(i = 1; i <= n; ++i) {
            for(j = 0; j < length && squares[j] <= i; ++j) {
                dp[i] = min(dp[i], dp[i - squares[j]] + 1);
            }
        }
        return dp[n];
    }
private:
    bool judge(int &n) {
        double m = sqrt(static_cast<double>(n));
        return m == static_cast<long>(m);
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