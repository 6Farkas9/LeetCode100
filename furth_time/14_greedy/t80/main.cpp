#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string s = "eccbbbbdec";

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> final_pos;
        int length = s.size();
        for(int i = 0; i < length; ++i)
            final_pos[s[i]] = i;
        int cs = 0, ce = final_pos[s[0]];
        for(int i = 1; i < length; ++i) {
            if(i > ce) {
                ans.push_back(ce - cs + 1);
                cs = i;
                ce = final_pos[s[i]];
            }
            else {
                ce = max(ce, final_pos[s[i]]);
            }
        }
        ans.push_back(length - cs);
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.partitionLabels(s);
    for(auto val : ans) cout << val << " ";
    cout << endl;
}