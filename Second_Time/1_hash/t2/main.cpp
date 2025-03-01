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
        vector<vector<string>> res;
        int length = strs.size();
        unordered_map<string,int> str_hash;
        int count = 0;
        for(int i = 0; i < length; ++i){
            string str_source = strs[i];
            string str_sorted = str_source;
            sort(str_sorted.begin(), str_sorted.end());
            auto search_ans = str_hash.find(str_sorted);
            if(search_ans != str_hash.end()){
                res[search_ans->second].push_back(str_source);
            }
            else{
                vector<string> temp_vector;
                temp_vector.push_back(strs[i]);
                res.push_back(temp_vector);
                str_hash[str_sorted] = count++;
            }
        }
        return res;
    }
};

int main(){
    Solution A;
    vector<vector<string>> res = A.groupAnagrams(strs1);
    for(vector<string> i : res){
        for(string j : i){
            cout << j << " ";
        }
        cout << "next line" <<endl;
    }
}