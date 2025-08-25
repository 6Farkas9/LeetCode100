#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> nums{0,3,7,2,5,8,4,6,0,1};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> num_set;
        for(int &num : nums) {
            num_set.insert(num);
        }
        for(auto num : num_set) {
            if(num_set.find(num - 1) != num_set.end())
                continue;
            int length = 1;
            while(num_set.find(num + length) != num_set.end()) {
                ++length;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.longestConsecutive(nums);
    cout << res << endl;
}