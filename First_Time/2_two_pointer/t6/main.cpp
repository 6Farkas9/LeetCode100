#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<int> nums{0,0,0,0};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        cout << endl;
        for(int i = 0;i < nums.size() && nums[i] <= 0;){
            int j = i + 1;
            int k = nums.size() - 1;
            bool move_j = true;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp{nums[i] ,nums[j] ,nums[k]};
                    res.push_back(temp);
                    if(move_j){
                        int temp = nums[j];
                        while(j <= k && nums[j] == temp){
                            j++;
                        }
                    }
                    else{
                        int temp = nums[k];
                        while(j <= k && nums[k] == temp){
                            k--;
                        }
                    }
                    move_j = !move_j;
                }
                else if(nums[i] + nums[j] + nums[k] < 0){
                    int temp = nums[j];
                    while(j <= k && nums[j] == temp){
                        j++;
                    }
                }
                else{
                    int temp = nums[k];
                    while(j <= k && nums[k] == temp){
                        k--;
                    }
                }
            }
            int temp = nums[i];
            while(i < nums.size() && nums[i] <= 0 && nums[i] == temp){
                i++;
            }
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