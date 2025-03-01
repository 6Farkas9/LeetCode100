#include <iostream>
#include <stack>

using namespace std;

string s = "(";

class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
        if(length % 2 != 0) return false;
        stack<char> st;
        for(int i = 0; i < length; ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')   st.push(s[i]);
            else{
                if(st.empty())  return false;
                char ch = st.top();
                st.pop();
                if(!(ch == '(' && s[i] == ')') && !(ch == '[' && s[i] == ']') && !(ch == '{' && s[i] == '}'))
                    return false;
            }
        }
        return st.empty();
    }
};

int main(){
    Solution A;
    auto res =  A.isValid(s);
    cout << res << endl;
}