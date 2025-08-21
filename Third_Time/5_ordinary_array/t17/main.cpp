#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{1,1};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            while(nums[i] > 0 && nums[i] <= length && nums[nums[i] - 1] != nums[i]){
                int j = nums[i] - 1;
                swap(nums[i], nums[j]);
            }
        }
        for(int i = 0; i < length; ++i){
            if(nums[i] != i + 1)    return i + 1;
        }
        return length + 1;
    }
};

int main(){
    Solution A;
    int res = A.firstMissingPositive(nums);
    cout << res << endl;
}