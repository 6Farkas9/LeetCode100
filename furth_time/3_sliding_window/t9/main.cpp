#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string s = "cbaebabacd";
string p = "abc";

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int s_length = s.size(), p_length = p.size();
        if(s_length < p_length)
            return ans;
        unordered_map<char, int> p_count, s_count;
        for(char & ch : p) {
            ++p_count[ch];
        }
        int pz = p_count.size();
        int z_count = 0, i = 0, j = 0;
        while(i < s_length && p_count.find(s[i]) == p_count.end())
            ++i;
        j = i;
        while(j < s_length) {
            if(p_count.find(s[j]) == p_count.end()) {
                i = j + 1;
                while(i < s_length && p_count.find(s[i]) == p_count.end())
                    ++i;
                j = i;
                z_count = 0;
                s_count.clear();
            }
            else {
                if(s_count[s[j]] == p_count[s[j]]) {
                    --z_count;
                }
                ++s_count[s[j]];
                if(s_count[s[j]] == p_count[s[j]]) {
                    ++z_count;
                }
                if(j - i + 1 > p_length) {
                    if(s_count[s[i]] == p_count[s[i]]) {
                        --z_count;
                    }
                    --s_count[s[i]];
                    if(s_count[s[i]] == p_count[s[i]]) {
                        ++z_count;
                    }
                    ++i;
                }
                ++j;
            }
            // cout << i << "," << j << "," << z_count << "," << pz << endl;
            if(z_count == pz) {
                ans.emplace_back(i);
            }
            
        }
        return ans;
    }
};

int main(){
    Solution A;
    vector<int> res = A.findAnagrams(s,p);
    for(int val : res){
        cout << val << ",";
    }
    cout << endl;
}