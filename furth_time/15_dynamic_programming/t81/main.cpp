#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int n = 3;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        int last1 = 2, last2 = 1, ans;
        for(int i = 2; i < n; ++i) {
            ans = last1 + last2;
            last2 = last1;
            last1 = ans;
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.climbStairs(n);
    cout << ans << endl;
}