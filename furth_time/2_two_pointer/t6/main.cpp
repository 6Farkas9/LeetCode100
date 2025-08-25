#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

vector<int> nums{-1,0,1,2,-1,-4};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> num_map;
        for(auto & num : nums) {
            ++num_map[num];
        }
        int i = 0, j = 1, length = nums.size();
        while(i < length && j < length) {
            while(j < length) {
                int third_num = 0 - nums[i] - nums[j];
                if(third_num >= nums[j] && num_map.find(third_num) != num_map.end()) {
                    int count = num_map[0 - nums[i] - nums[j]];
                    if(nums[i] == third_num)
                        --count;
                    if(nums[j] == third_num)
                        --count;
                    if(count > 0){
                        ans.emplace_back(vector<int>());
                        ans.back().emplace_back(nums[i]);
                        ans.back().emplace_back(nums[j]);
                        ans.back().emplace_back(0 - nums[i] - nums[j]);
                    }
                }
                do{
                    ++j;
                }while(j < length && nums[j - 1] == nums[j]);
            }
            do{
                ++i;
            }while(i < length && nums[i - 1] == nums[i]);
            j = i + 1;
        }
        return ans;
    }
};

int main(){
    Solution A;
    vector<vector<int>> res = A.threeSum(nums);
    for(vector<int> i : res){
        cout << "[";
        for(int j : i){
            cout << j << " ";
        }
        cout << "]" << endl;
    } 
}