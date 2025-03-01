#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> heights = {2,4};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        if(length == 1) return heights[0];
        vector<int> edge_left(length), edge_right(length);
        stack<int> stack_left, stack_right;
        for(int i = 0, j = length - 1; i < length; ++i, --j){
            edge_left[i] = i; 
            while(!stack_left.empty() && heights[i] <= heights[stack_left.top()]){
                edge_left[i] = edge_left[stack_left.top()];
                stack_left.pop();
            }
            stack_left.push(i);
            edge_right[j] = j;
            while(!stack_right.empty() && heights[j] <= heights[stack_right.top()]){
                edge_right[j] = edge_right[stack_right.top()];
                stack_right.pop();
            }
            stack_right.push(j);
        }
        int ans = 0;
        for(int i = 0; i < length; ++i){
            ans = max(ans, heights[i] * (edge_right[i] - edge_left[i] + 1));
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.largestRectangleArea(heights);
    cout << res << endl;
}