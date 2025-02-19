#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {2,2,1,1,1,2,2};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, count = 0;
        for(int & val : nums){
            if(count == 0)  ans = val;
            if(val == ans)  count++;
            else count--; 
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.majorityElement(nums);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}