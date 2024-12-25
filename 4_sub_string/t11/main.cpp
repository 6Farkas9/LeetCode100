#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> nums{1};
int k = 1;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> res;
        deque<int> max_store;
        for(int i=0; i<nums.size(); i++){
            while(!max_store.empty() && nums[max_store.back()] <= nums[i]){
                max_store.pop_back();
            }
            max_store.push_back(i);
            while(max_store.front() <= i-k){
                max_store.pop_front();
            }
            if(i>=(k-1))
                res.push_back(nums[max_store.front()]);
        }
        return res;
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