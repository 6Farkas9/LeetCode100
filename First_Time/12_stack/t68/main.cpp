#include <iostream>
#include <stack>

using namespace std;

string s = "(";

class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
        stack<char> data;
        for(int i = 0; i < length; i++){
            char c_str = s.at(i);
            if(c_str == '(' || c_str == '{' || c_str == '['){
                data.push(c_str);
            }
            else{
                if(data.empty()) return false;
                char c_last = data.top();
                data.pop();
                if(c_str == ')'){
                    if(c_last != '(') return false;
                }
                if(c_str == '}'){
                    if(c_last != '{') return false;
                }
                if(c_str == ']'){
                    if(c_last != '[') return false;
                }
            }
        }
        if(data.empty())    return true;
        else    return false;
    }
};

int main(){
    Solution A;
    auto res =  A.isValid(s);
    cout << res << endl;
}