#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

string digits = "";

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length = digits.size();
        if(!length)
            return this->ans;
        recursion(digits, 0, length);
        return this->ans;
    }
private:
    vector<string> ans;
    string current;
    unordered_map<char,vector<char>> table = {
        {'2' , {'a','b','c'}},
        {'3' , {'d','e','f'}},
        {'4' , {'g','h','i'}},
        {'5' , {'j','k','l'}},
        {'6' , {'m','n','o'}},
        {'7' , {'p','q','e','s'}},
        {'8' , {'t','u','v'}},
        {'9' , {'w','x','y','z'}}
    };
    void recursion(string & digits, int i, int & length){
        if(i == length){
            this->ans.push_back(this->current);
            return;
        }
        char current_int = digits[i];
        for(char ch : table[current_int]){
            this->current.push_back(ch);
            recursion(digits, i+1, length);
            this->current.pop_back();
        }
    }
};

int main(){
    Solution A;
    vector<string> res = A.letterCombinations(digits);
    cout << res.size() << endl;
    for(auto str : res) cout << str << endl;
}