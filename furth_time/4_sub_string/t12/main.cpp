#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;
//          0123456789 
string s = "ADOBECODEBANC";
string t = "ABC";

class Solution {
public:
    string minWindow(string s, string t) {
        int ans_start_pos = -1, ans_length = INT_MAX;
        unordered_map<char, int> s_count, t_count;
        int s_length = s.size(), t_length = t.size();
        for(int i = 0; i < t_length; ++i) {
            ++t_count[t[i]];
        }
        int greater_num = 0, t_num = t_count.size();
        int i = 0, j = 0;
        while(j < s_length) {
            if(t_count.find(s[j]) != t_count.end()) {
                ++s_count[s[j]];
                if(s_count[s[j]] == t_count[s[j]]) {
                    ++greater_num;
                }
                // 右移i
                while(t_count.find(s[i]) == t_count.end() || s_count[s[i]] > t_count[s[i]]) {
                    if(t_count.find(s[i]) != t_count.end()) {
                        --s_count[s[i]];
                    }
                    ++i;
                }
            }
            // cout << i << "," << j << "," << greater_num << "," << ans_start_pos << "," << ans_length << endl;
            if(greater_num == t_num) {
                if(j - i + 1 < ans_length) {
                    ans_start_pos = i;
                    ans_length = j - i + 1;
                }
            }
            ++j;
        }
        return ans_start_pos == -1 ? "" : s.substr(ans_start_pos, ans_length);
    }
};

int main(){
    Solution A;
    string res = A.minWindow(s,t);
    cout << res << endl;
}