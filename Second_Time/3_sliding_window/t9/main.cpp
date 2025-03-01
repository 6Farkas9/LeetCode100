#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string s = "aaabb";
string p = "bb";

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int length_s = s.size();
        int length_p = p.size();
        vector<int> ans;
        if(length_p > length_s) return ans;
        vector<int> count(26);
        for(int i = 0; i < length_p; ++i){
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }
        int differ = 0;
        for(int i = 0; i < 26; i++){
            if(count[i])    ++differ;
        }
        if(!differ) ans.emplace_back(0);
        int s_start = 0, s_end = length_p;
        while(s_end < length_s){
            if(count[s[s_start] - 'a'] == 0){
                ++differ;
            }
            --count[s[s_start] - 'a'];
            if(count[s[s_start] - 'a'] == 0){
                --differ;
            }
            ++s_start;
            if(count[s[s_end] - 'a'] == 0){
                ++differ;
            }
            ++count[s[s_end] - 'a'];
            if(count[s[s_end] - 'a'] == 0){
                --differ;
            }
            ++s_end;
            if(!differ) ans.emplace_back(s_start);
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