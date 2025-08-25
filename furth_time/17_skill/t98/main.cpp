#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {1,2,0};
                    // 1 0 0 0 1 1 2 2 2 2
                    // 0 1 0 0 1 1 2 2 2 2
                    // 0 0 1 0 1 1 2 2 2 2
                    // 0 0 0 1 1 1 2 2 2 2


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int i = 0, j = 0;
        for(int c = 0; c < length;) {
            if(nums[c] == 0) {
                if(i == c) {
                    ++i;
                    ++j;
                    ++c;
                }
                else if(i == j) {
                    swap(nums[i], nums[c]);
                    ++i;
                    ++j;
                }
                else {
                    swap(nums[i], nums[c]);
                    ++i;
                }
            }
            else if(nums[c] == 1) {
                if(j == c) {
                    ++j;
                    ++c;
                }
                else {
                    swap(nums[j], nums[c]);
                    ++j;
                }
            }
            else {
                ++c;
            }
        }
    }
};

int main(){
    Solution A;
    A.sortColors(nums);

    // cout << ans << endl;

    for(auto val : nums){
        cout << val << " ";
    }
    cout << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}