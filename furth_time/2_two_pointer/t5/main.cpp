#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{1,8,6,2,5,4,8,3,7};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size() - 1;
        int i = 0, j = width;
        int ans = 0;
        while(i < j) {
            if(height[i] < height[j]) {
                ans = max(ans, width * height[i]);
                ++i;
            }
            else {
                ans = max(ans, width * height[j]);
                --j;
            }
            --width;
        }
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.maxArea(nums);
    cout << res << endl;
}