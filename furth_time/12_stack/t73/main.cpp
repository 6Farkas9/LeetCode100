#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> heights = {1,1,1,1};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        vector<int> left(length), right(length);
        left[0] = 0, right[length - 1] = length - 1;
        stack<int> sk;
        sk.push(0);
        for(int i = 1; i < length; ++i) {
            if(heights[i] > heights[sk.top()]) {
                left[i] = i;
                
            }
            else {
                while(!sk.empty() && heights[i] <= heights[sk.top()]) {
                    left[i] = left[sk.top()];
                    sk.pop();
                }
            }
            sk.push(i);
        }
        while(!sk.empty())  sk.pop();
        sk.push(length - 1);
        for(int i = length - 2; i >= 0; --i) {
            if(heights[i] > heights[sk.top()]) {
                right[i] = i;
            }
            else {
                while(!sk.empty() && heights[i] <= heights[sk.top()]) {
                    right[i] = right[sk.top()];
                    sk.pop();
                }
            }
            sk.push(i);
        }
        int ans = INT_MIN;
        for(int i = 0; i < length; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.largestRectangleArea(heights);
    cout << res << endl;
}