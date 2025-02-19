#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string s = "abcabcbb";

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        if(length == 0) return 0;
        int i = 0, j = i + 1;
        int res = 1;
        unordered_set<char> sub_str;
        sub_str.insert(s[i]);
        while(i < length && j < length){
            if(sub_str.find(s[j]) == sub_str.end()){
                sub_str.insert(s[j]);
                if(j - i + 1 > res) res = j - i + 1;
            }
            else{
                while(s[i] != s[j]){
                    sub_str.erase(s[i++]);
                }
                ++i;
            }
            ++j;
        }
        return res;
    }
};

int main(){
    Solution A;
    int res = A.lengthOfLongestSubstring(s);
    cout << res << endl;
}