#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> nums = {3};
int k = 1;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->min_heap.resize(k);
        this->current_pos = 0;
        int length = nums.size();
        for(int i = 0; i < length; i++){
            if(this->current_pos < k){
                this->min_heap[current_pos] = nums[i];
                // 自底向上调整
                int c_pos = current_pos++;
                int parent_pos = c_pos / 2;
                while(this->min_heap[parent_pos] > this->min_heap[c_pos]){
                    swap(this->min_heap[parent_pos], this->min_heap[c_pos]);
                    c_pos = parent_pos;
                    parent_pos = c_pos / 2;
                }
            }
            else if(nums[i] > this->min_heap[0]){
                this->min_heap[0] = nums[i];
                // 自顶向下调整
                int c_pos = 0;
                int child_left = c_pos * 2;
                int child_right = c_pos * 2 + 1;
                while(child_right < k && 
                (this->min_heap[c_pos] > this->min_heap[child_left] || this->min_heap[c_pos] > this->min_heap[child_right])){
                    int next_pos = child_left;
                    if(this->min_heap[child_right] < this->min_heap[child_left])    next_pos = child_right;
                    swap(this->min_heap[c_pos], this->min_heap[next_pos]);
                    c_pos = next_pos;
                    child_left = c_pos * 2;
                    child_right = c_pos * 2 + 1;
                }
                if(child_left < k && this->min_heap[c_pos] > this->min_heap[child_left])
                    swap(this->min_heap[c_pos], this->min_heap[child_left]);
            }
        }
        return this->min_heap[0];
    }
private:
    vector<int> min_heap;
    int current_pos;
};

int main(){
    Solution A;
    auto res =  A.findKthLargest(nums, k);
    cout << res << endl;
}