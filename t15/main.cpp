#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
vector<int> nums{1,2,3,4,5,6};
int k = 3;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        if(k > length){
            k = k % length;
        }
        if(k == 0 || k == length){
            return;
        }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
    }
};

int main(){
    Solution A;
    A.rotate(nums, k);
    for(auto i : nums){
        cout << i << " ";
    }
    cout << endl;
}