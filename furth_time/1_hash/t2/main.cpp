#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> strs1{"eat", "tea", "tan", "ate", "nat", "bat"};
vector<string> strs2{""};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> sorted_strs;
        for(auto & str : strs) {
            string str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            if(sorted_strs.find(str_copy) == sorted_strs.end()){
                sorted_strs[str_copy] = ans.size();
                ans.emplace_back(vector<string>());
            }
            ans[sorted_strs[str_copy]].emplace_back(std::move(str));
        }
        return ans;
    }
};

int main(){
    Solution A;
    vector<vector<string>> res = A.groupAnagrams(strs2);
    for(vector<string> i : res){
        for(string j : i){
            cout << j << " ";
        }
        cout << "next line" <<endl;
    }
}