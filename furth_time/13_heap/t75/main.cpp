#include <iostream>
#include <queue>
#include <unordered_map>
#include <functional>

using namespace std;

vector<int> nums = {1,1,1,2,2,3};
int k = 2;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequence;
        int length = nums.size(), i;
        for(int i = 0; i < length; ++i) {
            ++frequence[nums[i]];
        }
        vector<int> heap;
        for(auto &kv : frequence) {
            if(heap.size() < k) {
                heap.push_back(kv.first);
                correctHeapUp(heap, frequence);
            }   
            else {
                if(frequence[heap[0]] < kv.second) {
                    heap[0] = kv.first;
                    correctHeapDown(heap, frequence);
                }
            }
        }
        return heap;
    }
private:
    void correctHeapUp(vector<int> &heap, unordered_map<int, int> &frequence) {
        int length = heap.size() - 1;
        int i = length, j = (i - 1) / 2;
        while(i) {
            if(frequence[heap[i]] < frequence[heap[j]]) {
                swap(heap[i], heap[j]);
                i = j;
                j = (i - 1) / 2;
            }
            else
                break;
        }
    }
    void correctHeapDown(vector<int> &heap, unordered_map<int, int> &frequence) {
        int length = heap.size();
        int i = 0, l = i * 2, r = (i + 1) * 2, j;
        while(l < length && r < length) {
            if(frequence[heap[i]] <= frequence[heap[l]] && frequence[heap[i]] <= frequence[heap[r]])
                break;
            j = heap[l] <= heap[r] ? l : r;
            swap(heap[i], heap[j]);
            i = j;
            l = i * 2, r = (i + 1) * 2;
        }
    }
};

int main(){
    Solution A;
    auto res =  A.topKFrequent(nums, k);
    for(auto val : res) cout << val << " ";
    cout << endl;
}