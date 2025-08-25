#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> nums{1,3,1,2,0,5};
int k = 3;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> max_seq;
        for(int i = 0; i < k; ++i) {
            while(!max_seq.empty() && nums[i] > nums[max_seq.back()]) {
                max_seq.pop_back();
            }
            max_seq.push_back(i);
        }
        vector<int> ans;
        ans.emplace_back(nums[max_seq.front()]);
        int length = nums.size();
        int i = 0, j = k;
        for(; j < length; ++i, ++j) {
            while(!max_seq.empty() && nums[j] > nums[max_seq.back()]) {
                max_seq.pop_back();
            }
            max_seq.push_back(j);
            if(i == max_seq.front())
                max_seq.pop_front();
            ans.emplace_back(nums[max_seq.front()]);
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