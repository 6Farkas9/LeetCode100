#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int n = 4;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        for(int i = 0; i < n; ++i)  null_line.push_back('.');
        vector<string> temp;
        bitset<9> up, left, right;
        up.set();
        left.set();
        right.set();
        recursion(0, n, up, left, right, temp, ans);
        return ans;
    }
private:
    string null_line = "";
    void recursion(int i, int &n, bitset<9> &up, bitset<9> &left, bitset<9> &right, vector<string> &temp, vector<vector<string>> &ans) {
        if(i >= n) {
            ans.emplace_back(temp);
            return;
        }
        bitset<9> available_pos = up & left & right;
        if(!available_pos.count())  return;
        int j = 0, k = 8;
        while(j < n) {
            if(available_pos[k]) {
                temp.emplace_back(null_line);
                temp.back()[j] = 'Q';
                up[k] = left[k] = right[k] = false;
                bool origin_left = left[0];
                bool origin_right = right[8];
                left = left >> 1;
                right = right << 1;
                left[8] = right[0] = true;
                recursion(i + 1, n, up, left, right, temp, ans);
                left = left << 1;
                right = right >> 1;
                left[0] = origin_left;
                right[8] = origin_right;
                up[k] = left[k] = right[k] = true;
                temp.pop_back();
            }
            ++j;
            --k;
        }
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