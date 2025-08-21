#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> nums = {2,2,1};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int &num : nums)    ans = ans ^ num;
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.singleNumber(nums);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}