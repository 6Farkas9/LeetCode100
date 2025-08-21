#include <iostream>
#include <queue>
#include <functional>

using namespace std;

vector<int> nums = {1,3,6,8,4,0,7,9};
int k = 4;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            if(heap.size() < k){
                heap.push_back(nums[i]);
                int child = heap.size() - 1;
                int parent = (child - 1) / 2;
                while(child > 0 && heap[parent] > heap[child]){
                    swap(heap[child], heap[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
            }
            else{
                if(nums[i] > heap[0]){
                    heap[0] = nums[i];
                    int limit = heap.size();
                    int source = 0;
                    int lchild = source * 2 + 1, rchild = (source + 1) * 2;
                    while(lchild < limit && rchild < limit){
                        int target = heap[lchild] <= heap[rchild] ? lchild : rchild;
                        if(heap[source] <= heap[target])    break;
                        swap(heap[source], heap[target]);
                        source = target;
                        lchild = source * 2 + 1, rchild = (source + 1) * 2;
                    }
                    if(lchild < limit && heap[lchild] < heap[source])   swap(heap[source], heap[lchild]);
                }
            }
        }
        return heap[0];
    }
};

int main(){
    Solution A;
    auto res =  A.findKthLargest(nums, k);
    cout << res << endl;
}