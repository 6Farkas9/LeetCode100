#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> nums = {0};

class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size() - 1;
        int search_pos = 0, current_pos = 0, search_end, next_pos;
        int ans = 0;
        while(true){
            if(current_pos == length) break;
            else if(current_pos + nums[current_pos] >= length){
                ++ans;
                break;
            }
            search_end = current_pos + nums[current_pos];
            next_pos = search_pos;
            for(;search_pos <= search_end; ++search_pos){
                if(search_pos + nums[search_pos] >= next_pos + nums[next_pos])  next_pos = search_pos;
            }
            current_pos = next_pos;
            ++ans;
        }
        return ans;
    }
};

int main(){
    Solution A;
    int ans = A.jump(nums);
    cout << ans << endl;
}