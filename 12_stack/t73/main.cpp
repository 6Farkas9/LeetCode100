#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> heights = {1};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> max_can_use;
        int length = heights.size();
        vector<int> left_edge(length, -1), right_edge(length, length);
        int ans = 0;
        for(int i = 0; i < length; i++){
            int current_h = heights[i];
            while(!max_can_use.empty() && current_h <= heights[max_can_use.top()]){
                right_edge[max_can_use.top()] = i;
                max_can_use.pop();
            }
            left_edge[i] = (max_can_use.empty() ? -1: max_can_use.top());
            max_can_use.push(i);
        }
        for(int i = 0; i < length; i++){
            ans = max(ans, heights[i] * (right_edge[i] - left_edge[i] - 1));
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.largestRectangleArea(heights);
    cout << res << endl;
}