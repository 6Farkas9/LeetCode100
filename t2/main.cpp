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
        unordered_map<string,int> hash_str;
        vector<vector<string>> res;
        int location = 0;
        for(int i=0; i<strs.size(); i++){
            string str_c = strs[i];
            string str_sorted = str_c;
            sort(str_sorted.begin(),str_sorted.end());
            auto search_ans = hash_str.find(str_sorted);
            if(search_ans == hash_str.end()){
                hash_str[str_sorted] = res.size();
                vector<string> new_one{str_c};
                res.push_back(new_one);
            }
            else{
                res[search_ans->second].push_back(str_c);
            }
        }
        return res;
    }
};

int main(){
    Solution A;
    vector<vector<string>> res = A.groupAnagrams(strs2);
    for(vector<string> i : res){
        for(string j : i){
            cout << j << " ";
        }
        cout << "下一行" <<endl;
    }
}