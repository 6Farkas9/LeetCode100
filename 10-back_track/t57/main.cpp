#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

string digits = "23";

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length = digits.size();
        if(!length) return ans;
        recursion(digits, 0, length);
        return this->ans;
    }
private:
    vector<string> ans;
    vector<char> current_ans;
    unordered_map<char,vector<char>> table = {
        {'2' , {'a','b','c'}},
        {'3' , {'d','e','f'}},
        {'4' , {'g','h','i'}},
        {'5' , {'j','k','l'}},
        {'6' , {'m','n','o'}},
        {'7' , {'p','q','r','s'}},
        {'8' , {'t','u','v'}},
        {'9' , {'w','x','y','z'}}
    };
    void recursion(string &digits, int start, int &end){
        if(start == end){
            string temp = "";
            for(char ch : this->current_ans)    temp += ch;
            this->ans.push_back(temp);
        }
        int length = this->table[digits[start]].size();
        for(int i = 0; i < length; ++i){
            this->current_ans.push_back(table[digits[start]][i]);
            recursion(digits, start + 1, end);
            this->current_ans.pop_back();
        }
    }
};

int main(){
    Solution A;
    vector<string> res = A.letterCombinations(digits);
    cout << res.size() << endl;
    for(auto str : res) cout << str << endl;
}