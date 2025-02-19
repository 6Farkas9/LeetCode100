#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nums = {1};
int k = 1;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        this->min_heap.resize(k);
        this->current_pos = 0;
        for(int val : nums) counts[val]++;
        for(auto counts_pair : counts){
            if(this->current_pos < k){
                this->min_heap[current_pos] = counts_pair.first;
                // 自底向上调整
                int c_pos = current_pos++;
                int parent_pos = c_pos / 2;
                while(counts[this->min_heap[parent_pos]] > counts[this->min_heap[c_pos]]){
                    swap(this->min_heap[parent_pos], this->min_heap[c_pos]);
                    c_pos = parent_pos;
                    parent_pos = c_pos / 2;
                }
            }
            else if(counts_pair.second > counts[this->min_heap[0]]){
                this->min_heap[0] = counts_pair.first;
                // 自顶向下调整
                int c_pos = 0;
                int child_left = c_pos * 2;
                int child_right = c_pos * 2 + 1;
                while(child_right < k && 
                     (counts[this->min_heap[c_pos]] > counts[this->min_heap[child_left]] || 
                      counts[this->min_heap[c_pos]] > counts[this->min_heap[child_right]])){
                    int next_pos = child_left;
                    if(counts[this->min_heap[child_right]] < counts[this->min_heap[child_left]])    next_pos = child_right;
                    swap(this->min_heap[c_pos], this->min_heap[next_pos]);
                    c_pos = next_pos;
                    child_left = c_pos * 2;
                    child_right = c_pos * 2 + 1;
                }
                if(child_left < k && counts[this->min_heap[c_pos]] > counts[this->min_heap[child_left]])
                    swap(this->min_heap[c_pos], this->min_heap[child_left]);
            }
        }
        return this->min_heap;
    }
private:
    vector<int> min_heap;
    int current_pos;
};

int main(){
    Solution A;
    auto res =  A.topKFrequent(nums, k);
    for(auto val : res) cout << val << " ";
    cout << endl;
}