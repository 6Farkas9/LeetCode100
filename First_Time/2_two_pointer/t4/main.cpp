#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{4,2,4,0,0,3,0,5,1,0};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insert_pos = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0){
                nums[insert_pos] = nums[i];
                insert_pos++;
            }
        }
        for(int i = insert_pos;i<nums.size();i++)
            nums[i] = 0;
    }
};

int main(){
    Solution A;
    A.moveZeroes(nums);
    for(int val : nums)
        cout << val << " ";
    cout << endl;
}