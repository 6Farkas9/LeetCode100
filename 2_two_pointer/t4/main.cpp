#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{4,2,4,0,0,3,0,5,1,0};
// vector<int> nums{0};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int length = nums.size();
        while(i < length){
            if(nums[i] == 0){
                if(j < i)   j = i + 1;
                while(j < length && nums[j] == 0)   ++j;
                if(j < length){
                    swap(nums[i], nums[j]);
                }
                else{
                    break;
                }
            }
            else{
                ++i;
            }
        }
    }
};

int main(){
    Solution A;
    A.moveZeroes(nums);
    for(int val : nums)
        cout << val << " ";
    cout << endl;
}