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
        int ans = heights[0];
        if(length == 1) return ans;
        stack<int> st;
        vector<int> width(length);
        for(int i = 0; i < length; ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                width[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            width[st.top()] = length;
            st.pop();
        }
        for(int i = length - 1; i >= 0; --i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                width[st.top()] = width[st.top()] - i - 1;
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i < length; ++i)
            ans = max(ans, heights[i] * width[i]);
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.largestRectangleArea(heights);
    cout << res << endl;
}