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
        int len_s = s.size();
        int len_t = t.size();
        if(len_s < len_t){
            return "";
        }
        unordered_map<char,int> t_num;
        unordered_map<char,int> w_num;
        unordered_set<char> t_ele;
        unordered_set<char> w_ele;
        for(int i=0;i<len_t;i++){
            t_num[t[i]]++;
            w_num[t[i]] = 0;
            t_ele.emplace(t[i]);
        }
        int win_l = 0;
        while(win_l<len_s && t_num.find(s[win_l]) == t_num.end()){
            win_l++;
        }
        if(win_l == len_s){
            return "";
        }
        int win_r = win_l;
        int length = INT_MAX;
        int res_l = -1;
        deque<int> all_pos;
        while(win_r < len_s){
            if(t_num.find(s[win_r]) != t_num.end()){
                all_pos.push_back(win_r);
                w_num[s[win_r]]++;
                if(w_num[s[win_r]] >= t_num[s[win_r]]){
                    w_ele.emplace(s[win_r]);
                }
                while(t_ele == w_ele){
                    int temp_length = win_r - win_l + 1;
                    if(temp_length < length){
                        length = temp_length;
                        res_l = win_l;
                    }
                    w_num[s[all_pos.front()]]--;
                    if(w_num[s[all_pos.front()]] < t_num[s[all_pos.front()]]){
                        w_ele.erase(s[all_pos.front()]);
                    }
                    all_pos.pop_front();
                    win_l = all_pos.front();
                }
            }
            win_r++;
        }
        return res_l == -1?string():s.substr(res_l,length);
    }
};

int main(){
    Solution A;
    string res = A.minWindow(s,t);
    cout << res << endl;
}