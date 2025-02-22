#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

string s = "abbab";

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int length = s.size();
        vector<vector<bool>> judge(length,vector<bool>(length,true));
        for(int k = length - 1; k > 0; k--){
            for(int i = 0,j = length - k; j < length; i++,j++){
                judge[i][j] = (judge[i+1][j-1] && s.at(i) == s.at(j));
            }
        }
        recursion(s, judge, 0, length);
        return this->ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> current;
    void recursion(string & s, vector<vector<bool>> & judge, int i, int & length){
        if(i >= length){
            this->ans.push_back(this->current);
            return;
        }
        int j = i;
        for(; j < length; j++){
            if(judge[i][j]){
                this->current.push_back(s.substr(i,j-i+1));
                recursion(s, judge, j+1, length);
                this->current.pop_back();
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