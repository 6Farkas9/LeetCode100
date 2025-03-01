#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{4,2,0,3,2,5};

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        int ans = 0;
        int left = 0, right = length - 1;
        int left_max = 0, right_max = 0;
        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(height[left] < right_max){
                ans += left_max - height[left];
                ++left;
            }
            else{
                ans += right_max - height[right];
                --right;
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.trap(nums);
    cout << res << endl;
}

