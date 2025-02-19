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
        int two_step_before = 1, one_step_before = 2, current;
        for(int i = 3; i <= n; i++){
            current = two_step_before + one_step_before;
            two_step_before = one_step_before;
            one_step_before = current;
        }
        return current;
    }
};

int main(){
    Solution A;
    auto ans = A.climbStairs(n);
    cout << ans << endl;
}