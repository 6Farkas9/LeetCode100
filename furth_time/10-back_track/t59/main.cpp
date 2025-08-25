#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n = 3;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        recursion(0, 0, n, temp, ans);
        return ans;
    }
private:
    void recursion(int ln, int rn, int &n, string &temp, vector<string> &ans) {
        if(ln == n) {
            if(rn == n)
                ans.emplace_back(temp);
            return;
        }
        temp.push_back('(');
        ++ln;
        recursion(ln, rn, n, temp, ans);
        int differ = ln - rn;
        for(int i = 1; i <= differ; ++i) {
            temp.push_back(')');
            recursion(ln, rn + i, n, temp, ans);
        }
        for(int i = 1; i <= differ; ++i) {
            temp.pop_back();
        }
        temp.pop_back();
    }
};

int main(){
    Solution A;
    vector<string> res = A.generateParenthesis(n);
    cout << res.size() << endl;
    for(auto val : res){
       cout << val << endl;
    }
}