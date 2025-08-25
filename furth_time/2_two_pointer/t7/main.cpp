#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        vector<int> l_max(length, height[0]);
        vector<int> r_max(length, height[length - 1]);
        int t_max = height[0];
        for(int i = 1; i < length; ++i) {
            t_max = max(t_max, height[i]);
            l_max[i] = t_max;
        } 
        t_max = height[length - 1];
        for(int i = length - 2; i >= 0; --i) {
            t_max = max(t_max, height[i]);
            r_max[i] = t_max;
        }
        --length;
        int ans = 0;
        for(int i = 1; i < length; ++i) {
            t_max = min(l_max[i], r_max[i]);
            if(t_max >= height[i]) {
                ans += t_max - height[i];
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

