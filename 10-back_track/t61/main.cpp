#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

string s = "abbab";

class Solution {
public:
    vector<vector<string>> partition(string s) {
        this->length = s.size();
        vector<vector<bool>> isreply(this->length, vector<bool>(this->length, true));
        for(int differ = 1; differ < this->length; ++differ){
            for(int j = differ; j < this->length; ++j){
                int i = j - differ;
                isreply[i][j] = isreply[i + 1][j - 1] && s[i] == s[j];
            }
        }
        recursion(s, isreply, 0);
        return this->ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> c_ans;
    int length;
    void recursion(string &s, vector<vector<bool>> &isreply, int i){
        if(i >= this->length){
            this->ans.push_back(this->c_ans);
            return;
        }
        for(int j = i; j < this->length; ++j){
            if(isreply[i][j]){
                this->c_ans.push_back(s.substr(i, j - i + 1));
                recursion(s, isreply, j + 1);
                this->c_ans.pop_back();
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