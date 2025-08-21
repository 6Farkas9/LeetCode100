#include <iostream>
#include <string>
#include <stack>

using namespace std;

// string s = "3[a]2[bc]";
// string s = "3[a2[c]]";
// string s = "2[abc]3[cd]ef";
string s = "abc3[cd]xyz";

class Solution {
public:
    string decodeString(string s){
        int length = s.size();
        stack<int> nums;
        stack<string> strs;
        string temp("");
        for(int i = 0; i < length; ++i){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                if(temp != ""){
                    strs.push(temp);
                    temp = "";
                }
                int num = 0;
                for(; s[i] >= '0' && s[i] <= '9'; ++i){
                    num = num * 10;
                    num += int(s[i] - '0');
                }
                nums.push(num);
                --i;
            }
            else if(ch == '['){
                strs.push("[");
            }
            else if(ch == ']'){
                while(strs.top() != "["){
                    temp = strs.top() + temp;
                    strs.pop();
                }
                strs.pop();
                int num = nums.top();
                nums.pop();
                string one = temp;
                while(--num){
                    temp = temp + one;
                }
            }
            else{
                temp += s[i];
            }
        }
        while(!strs.empty()){
            temp = strs.top() + temp;
            strs.pop();
        }
        return temp;
    }
};

int main(){
    Solution A;
    auto res =  A.decodeString(s);
    cout << res << endl;
}