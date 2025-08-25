#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

string digits = "23";

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int length = digits.size();
        if(!length) return ans;
        string temp = "";
        recursion(0, digits, temp, ans, length);
        return ans;
    }
private:
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
    void recursion(int i, string &digits, string &temp, vector<string> &ans, int &length) {
        if(i >= length) {
            ans.emplace_back(temp);
            return;
        }
        for(char &ch : table[digits[i]]) {
            temp.push_back(ch);
            recursion(i + 1, digits, temp, ans, length);
            temp.pop_back();
        }
    }
};

int main(){
    Solution A;
    vector<string> res = A.letterCombinations(digits);
    cout << res.size() << endl;
    for(auto str : res) cout << str << endl;
}