#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<int> nums{-1,0,1,2,-1,-4};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size() - 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i <= length && nums[i] <= 0;){
            int j = length;
            int k = i + 1;
            bool move_k = true;
            while(k < j){
                if(nums[i] + nums[k] + nums[j] == 0){
                    vector<int> temp{nums[i], nums[k], nums[j]};
                    res.push_back(temp);
                    if(move_k){
                        int origin_num = nums[k++];
                        while(k < j && nums[k] == origin_num)   ++k;
                    }
                    else{
                        int origin_num = nums[j--];
                        while(k < j && nums[j] == origin_num)   --j;
                    }
                    move_k = !move_k;
                }
                else if(nums[i] + nums[k] + nums[j] < 0){
                    int origin_num = nums[k++];
                    while(k < j && nums[k] == origin_num)   ++k;
                    move_k = false;
                }
                else{
                    int origin_num = nums[j--];
                    while(k < j && nums[j] == origin_num)   --j;
                    move_k = true;
                }
            }
            int origin_num = nums[i++];
            while(i <= length && nums[i] <= 0 && nums[i] == origin_num) ++i;
        }
        return res;
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