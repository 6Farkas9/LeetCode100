#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int n = 4;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        deque<bool> fromleft(n, true);
        deque<bool> fromright(n, true);
        vector<bool> fromup(n, true);
        this->null_line = "";
        for(int i = 0; i < n; ++i)  this->null_line += '.';
        recrusion(0, fromleft, fromright, fromup);
        return this->ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> c_ans;
    string null_line;
    int n;
    // 从0开始
    void recrusion(int c_line, deque<bool> &fromleft, deque<bool> &fromright, vector<bool> &fromup){
        if(c_line >= n){
            this->ans.push_back(this->c_ans);
            return;
        }
        vector<int> pos_all;
        for(int i = 0; i < this->n; ++i){
            if(fromleft[i] && fromright[i] && fromup[i]) pos_all.push_back(i);
        }
        if(pos_all.empty()) return;
        bool temp_left = fromleft.front(), temp_right = fromright.back();
        fromleft.pop_front();
        fromleft.push_back(true);
        fromright.pop_back();
        fromright.push_front(true);
        for(int pos : pos_all){
            this->c_ans.push_back(this->null_line);
            this->c_ans.back()[pos] = 'Q';
            if(pos - 1 >= 0)    fromleft[pos - 1] = false;
            if(pos + 1 < this->n)   fromright[pos + 1] = false;
            fromup[pos] = false;
            recrusion(c_line + 1, fromleft, fromright, fromup);
            if(pos - 1 >= 0)    fromleft[pos - 1] = true;
            if(pos + 1 < this->n)   fromright[pos + 1] = true;
            fromup[pos] = true;
            this->c_ans.pop_back();
        }
        fromleft.pop_back();
        fromleft.push_front(temp_left);
        fromright.pop_front();
        fromright.push_back(temp_right);
    }
};

int main(){
    Solution A;
    vector<vector<string>> res =  A.solveNQueens(n);
    cout << res.size() << endl;
    for(auto len : res){
        for(auto str : len){
            cout << str << " ";
        }
        cout << endl;
        cout << endl;
    }
}