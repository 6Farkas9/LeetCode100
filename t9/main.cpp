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
        vector<int> ans;
        if(p.size() > s.size()){
            return ans;
        }
        unordered_map<char,int> count_p;
        unordered_map<char,int> count_s;
        for(int i=0; i<p.size(); i++){
            count_s[s[i]]++;
            count_p[p[i]]++;
        }
        int s_start = 0;
        int s_end = p.size() - 1;
        while(s_end < s.size()){
            if(count_s == count_p){
                ans.emplace_back(s_start);
            }
            count_s[s[s_start++]]--;
            if(count_s[s[s_start - 1]] == 0){
                count_s.erase(s[s_start - 1]);
            }
            count_s[s[++s_end]]++;
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