#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;
//          0123456789 
string s = "aaaaaaaaaaaabbbbbcdd";
string t = "abcdd";

class Solution {
public:
    string minWindow(string s, string t) {
        int s_l = s.size(), t_l = t.size();
        if(t_l > s_l)   return "";
        int rest_l = t_l;
        int sub_l = INT_MAX;
        int start = 0, left_e = 0, right_e = 0;
        unordered_map<char,int> s_num, t_num;
        for(int i = 0; i < t_l; ++i){
            t_num[t[i]]++;
        }
        while(right_e < s_l){
            ++s_num[s[right_e]];
            if(t_num.find(s[right_e]) != t_num.end()){
                if(s_num[s[right_e]] == t_num[s[right_e]])  rest_l -= t_num[s[right_e]];
                if(rest_l == 0){
                    while(true){
                        if(t_num.find(s[left_e]) != t_num.end() && s_num[s[left_e]] == t_num[s[left_e]])    break;
                        --s_num[s[left_e]];
                        ++left_e;
                    }
                    if(right_e - left_e + 1 < sub_l){
                        sub_l = right_e - left_e + 1;
                        start = left_e;
                    }    
                }
            }
            ++right_e;
        }
        sub_l = sub_l == INT_MAX ? 0 : sub_l;
        return s.substr(start, sub_l);
    }
};

int main(){
    Solution A;
    string res = A.minWindow(s,t);
    cout << res << endl;
}