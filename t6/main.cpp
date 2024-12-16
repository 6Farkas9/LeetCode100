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