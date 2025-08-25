#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string s = "abba";

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        unordered_map<char, int> ch_pos;
        int i = 0, j = 0;
        int ans = 0;
        while(j < length) {
            if(ch_pos.find(s[j]) != ch_pos.end() && i < ch_pos[s[j]] + 1) {
                i = ch_pos[s[j]] + 1;
            }
            ch_pos[s[j]] = j;
            ++j;
            ans = max(ans, j - i);
        }
        return ans;
    }
};

int main(){
    Solution A;
    int res = A.lengthOfLongestSubstring(s);
    cout << res << endl;
}