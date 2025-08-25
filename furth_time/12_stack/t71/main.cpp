#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

// string s = "3[a]2[bc]";
string s = "3[a2[c]]";
// string s = "2[abc]3[cd]ef";

class Solution {
public:
    string decodeString(string s){
        int lenght = s.size(), repeat_num;
        stack<string> sk;
        string ans = "";
        const int differ = '0';
        for(int i = 0; i < lenght;) {
            if(isdigit(s[i])) {
                string num_str = "";
                while(isdigit(s[i])) {
                    num_str = num_str + s[i];
                    ++i;
                }
                sk.push(num_str);
            }
            else if(s[i] == '[') {
                sk.push("[");
                ++i;
            }
            else if(isalpha(s[i])) {
                string c_str = "";
                while(isalpha(s[i])) {
                    c_str = c_str + s[i];
                    ++i;
                }
                sk.push(c_str);
            }
            else{
                string c_str = "";
                while(sk.top() != "[") {
                    c_str = sk.top() + c_str;
                    sk.pop();
                }
                sk.pop();
                istringstream(sk.top()) >> repeat_num;
                sk.pop();
                string str = "";
                for(int j = 0; j < repeat_num; ++j) {
                    str = str + c_str;
                }
                sk.push(str);
                ++i;
            }
        }
        cout << sk.size() << endl;
        while(!sk.empty()) {
            ans = sk.top() + ans;
            sk.pop();
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.decodeString(s);
    cout << res << endl;
}