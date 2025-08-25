#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

string s = "abbab";

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int length = s.size();
        if(length == 0) return ans;
        vector<vector<bool>> judge(length, vector<bool>(length, true));
        int i, j, k;
        for(k = 1; k < length; ++k) {
            for(j = k; j < length; ++j) {
                i = j - k;
                judge[i][j] = (s[i] == s[j]) && judge[i + 1][j - 1];
            }
        }
        vector<string> temp;
        recursion(0, length, temp, ans, judge, s);
        return ans;
    }
private:
    void recursion(int i, int &length, vector<string> &temp, vector<vector<string>> &ans, vector<vector<bool>> &judge, string &s) {
        if(i >= length) {
            ans.emplace_back(temp);
            return;
        }
        for(int j = i; j < length; ++j) {
            if(judge[i][j]) {
                temp.emplace_back(s.substr(i, j - i + 1));
                recursion(j + 1, length, temp, ans, judge, s);
                temp.pop_back();
            }
        }
    }
};

int main(){
    Solution A;
    vector<vector<string>> res =  A.partition(s);
    cout << res.size() << endl;
    for(auto len : res){
        for(auto str : len){
            cout << str << " ";
        }
        cout << endl;
    }
}