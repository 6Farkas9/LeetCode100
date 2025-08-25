#include <iostream>
#include <stack>

using namespace std;

string s = "(";

class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
        if(length % 2)  return false;
        stack<char> sk;
        for(int i = 0; i < length; ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                sk.push(s[i]);
            else{
                if(s[i] == ')') {
                    if(sk.empty() || sk.top() != '(') return false;
                    sk.pop();
                }
                else if(s[i] == ']') {
                    if(sk.empty() || sk.top() != '[') return false;
                    sk.pop();
                }
                else {
                    if(sk.empty() || sk.top() != '{') return false;
                    sk.pop();
                }
            }
        }
        return sk.empty();
    }
};

int main(){
    Solution A;
    auto res =  A.isValid(s);
    cout << res << endl;
}