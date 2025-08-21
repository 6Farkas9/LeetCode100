#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> nums{1,3,1,2,0,5};
int k = 3;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size(), i;
        deque<int> dq;
        dq.push_back(0);
        for(i = 1; i < k; ++i){
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[dq.front()]);
        for(int j = 0; i < length; ++i, ++j){
            if(j == dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res = A.maxSlidingWindow(nums,k);
    for(int val : res){
        cout << val << " ";
    }
    cout << endl;
}