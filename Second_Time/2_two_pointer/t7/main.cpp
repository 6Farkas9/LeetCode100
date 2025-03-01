#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{1,2,3};

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        int i = 0, j = length - 1;
        int res = 0;
        int current_edge = i;
        int current_height = height[i];
        int temp_add = 0;
        while(i <= j){
            if(height[i] >= current_height){
                res += temp_add;
                temp_add = 0;
                current_edge = i;
                current_height = height[i];
            }
            else{
                temp_add += current_height - height[i];
            }
            ++i;
        }
        i = current_edge;
        current_edge = j;
        current_height = height[j];
        temp_add = 0;
        while(i <= j){
            if(height[j] >= current_height){
                res += temp_add;
                temp_add = 0;
                current_edge = j;
                current_height = height[j];
            }
            else{
                temp_add += current_height - height[j];
            }
            --j;
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.trap(nums);
    cout << res << endl;
}

