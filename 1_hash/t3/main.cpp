#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> nums{0,3,7,2,5,8,4,6,0,1};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> data;
        for(int val : nums){
            data.insert(val);
        }
        int res = 0;
        for(int val : data){
            if(data.find(val - 1) != data.end())    continue;
            int length = 1;
            while(data.find(val + length) != data.end())    length++;
            if(length > res)    res = length;
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.longestConsecutive(nums);
    cout << res << endl;
}