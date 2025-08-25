#include <iostream>
#include <queue>
#include <functional>

using namespace std;

vector<int> nums = {3,2,1,5,6,4};
int k = 2;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         vector<int> heap;
//         int length = nums.size(), i;
//         for(i = 0; i < k; ++i) {
//             heap.emplace_back(nums[i]);
//             correctHeapUp(heap);
//         }
//         for(; i < length; ++i) {
//             if(nums[i] <= heap[0])
//                 continue;
//             else {
//                 heap[0] = nums[i];
//                 correctHeapDown(heap);
//             }
//         }
//         return heap[0];
//     }
// private:
//     void correctHeapUp(vector<int> &heap) {
//         int i = heap.size() - 1, j;
//         j = (i - 1) / 2;
//         while(i > 0 && heap[i] < heap[j]) {
//             swap(heap[i], heap[j]);
//             i = j;
//             j = (i - 1) / 2;
//         }
//     }
//     void correctHeapDown(vector<int> &heap) {
//         int i = 0, length = heap.size(), j;
//         int l = i * 2 + 1, r = (i + 1) * 2;
//         while(l < length && r < length) {
//             if(heap[i] <= heap[l] && heap[i] <= heap[r]) {
//                 return;
//             }
//             j = heap[l] <= heap[r] ? l : r;
//             swap(heap[i], heap[j]);
//             i = j;
//             l = i * 2 + 1, r = (i + 1) * 2;
//         }
//         if(l < length && heap[i] > heap[l]) {
//             swap(heap[i], heap[l]);
//         }
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, deque<int>, function<bool(const int&, const int&)>> heap([&](const int& a, const int &b){
        //     return a > b;
        // });
        priority_queue<int, deque<int>, greater<int>> heap;
        int length = nums.size(), i;
        for(i = 0; i < k; ++i) {
            heap.push(nums[i]);
        }
        for(; i < length; ++i) {
            if(nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
private:
    
};

int main(){
    Solution A;
    auto res =  A.findKthLargest(nums, k);
    cout << res << endl;
}