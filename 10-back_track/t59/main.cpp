#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n = 3;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = n, right = n;
        vector<string> ans;
        string ca = "";
        recursion(n, 0, 0, ans, ca);
        return ans;
    }
private:
    void recursion(int &n, int left, int right, vector<string> &ans, string &ca){
        cout << ca << endl;
        if(left == n){
            for(int i = right; i < n; ++i)  ca.push_back(')');
            ans.push_back(ca);
            for(int i = right; i < n; ++i)  ca.pop_back();
            return;
        }
        ca.push_back('(');
        recursion(n, left + 1, right, ans, ca);
        ca.pop_back();
        if(left > right){
            ca.push_back(')');
            recursion(n, left, right + 1, ans, ca);
            ca.pop_back();
        }
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