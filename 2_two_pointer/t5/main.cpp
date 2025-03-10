#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{1,8,6,2,5,4,8,3,7};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while(i < j){
            int temp = min(height[i], height[j]) * (j - i);
            if(temp > res)  res = temp;
            if(height[i] <= height[j])  ++i;
            else    --j;
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.maxArea(nums);
    cout << res << endl;
}