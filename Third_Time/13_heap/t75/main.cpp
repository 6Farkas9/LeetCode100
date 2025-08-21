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
        unordered_map<int,int> count;
        vector<int> ans;
        for(int num : nums) ++count[num];
        function<bool(const int&,const int&)> compare = [&](const int& a,const int& b){
            return count[a] > count[b];
        };
        priority_queue<int, vector<int>, decltype(compare)> heap(compare);
        for(auto pair : count){
            if(heap.size() < k)
                heap.push(pair.first);
            else{
                if(pair.second > count[heap.top()]){
                    heap.pop();
                    heap.push(pair.first);
                }
            }
        }
        while(!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.topKFrequent(nums, k);
    for(auto val : res) cout << val << " ";
    cout << endl;
}