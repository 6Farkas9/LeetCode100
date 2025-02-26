#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string s = "eccbbbbdecf";

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> pos;
        int length = s.size();
        for(int i = 0; i < length; ++i) pos[s[i]] = i;
        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < length; ++i){
            end = max(end, pos[s[i]]);
            if(i == end){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.partitionLabels(s);
    for(auto val : ans) cout << val << " ";
    cout << endl;
}