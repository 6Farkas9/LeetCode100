#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s = "abc3[a2[c]vas2[b]]xyz";
// string s = "abc3[acd]]xyz";
// string s = "abc3[2[c]]xyz";
// string s = "123a";

class Solution {
public:
    string decodeString(string s){
        int length = s.size();
        stack<string> str_store;
        for(int i = 0; i < length; i++){
            if(s.at(i) >= '0' && s.at(i) <= '9'){
                string temp = "";
                while(s.at(i) >= '0' && s.at(i) <= '9'){
                    temp += s[i++];
                }
                str_store.push(temp);
                i--;
            }
            else if((s.at(i) >= 'a' && s.at(i) <= 'z') || s.at(i) == '['){
                string temp = "";
                temp = temp + s.at(i);
                str_store.push(temp);
            }
            else{
                string temp = "";
                temp = temp + str_store.top();
                str_store.pop();
                while(str_store.top() != "["){
                    temp = str_store.top() + temp;
                    str_store.pop();
                }
                str_store.pop();
                int repeat_num = stoi(str_store.top());
                str_store.pop();
                string temp_res = "";
                for(int j = 0; j < repeat_num; j++) temp_res += temp;
                str_store.push(temp_res);
            }
        }
        string res = "";
        while(!str_store.empty()){
            res = str_store.top() + res;
            str_store.pop();
        }
        return res;
    }
};

int main(){
    Solution A;
    auto res =  A.decodeString(s);
    cout << res << endl;
}