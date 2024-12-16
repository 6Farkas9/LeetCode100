#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> nums{0,3,7,2,5,8,4,6,0,1};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int val : nums){
            num_set.insert(val);
        }
        int res = 0;
        for(int val : num_set){
            if(num_set.find(val - 1) != num_set.end())
                continue;
            int current_len = 1;
            int add_size = 1;
            while(num_set.find(val + add_size) != num_set.end()){
                current_len++;
                add_size++;
            }
            if(current_len > res)
                res = current_len;
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.longestConsecutive(nums);
    cout << res << endl;
}