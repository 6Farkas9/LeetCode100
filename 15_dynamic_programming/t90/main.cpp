#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <unordered_set>
#include <stack>

using namespace std;

string s = ")()())";
// 0 1 2 3 4 5 6 7 8 9

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        if(!length) return 0;
        int ans = 0;
        stack<pair<char,int>> st;
        st.push(make_pair(')', -1));
        for(int i = 0; i < length; ++i){
            if(s[i] == '(' || st.top().first == ')') st.push(make_pair(s[i], i));
            else{
                st.pop();
                int j = st.top().second;
                ans = max(ans, i - j);
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.longestValidParentheses(s);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}