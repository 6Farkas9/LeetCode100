#include <iostream>
#include <queue>
#include <functional>

using namespace std;

vector<int> nums = {3};
int k = 1;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> heap;
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            heap.push(nums[i]);
            if(heap.size() > k) heap.pop();
        }
        return heap.top();
    }
};

int main(){
    Solution A;
    auto res =  A.findKthLargest(nums, k);
    cout << res << endl;
}