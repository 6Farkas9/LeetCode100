#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{4,2,3};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        int res = 0;
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            left_max[i] = max(left_max[i-1],height[i]);
        }
        for(int i=n-2; i>=0; i--){
            right_max[i] = max(right_max[i+1],height[i]);
        }
        for(int i=0; i<n; i++){
            int highest = min(left_max[i],right_max[i]);
            res += highest - height[i];
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.trap(nums);
    cout << res << endl;
}

