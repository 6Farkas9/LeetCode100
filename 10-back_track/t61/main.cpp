#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int n = 9;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->current_queen.assign(n, -1);
        this->n_origin = n;
        recursion(0,0,0,0);
        return this->ans;
    }
private:
    int n_origin;
    vector<vector<string>> ans;
    vector<int> current_queen;
    void recursion(int row, int colmuns, int diagonals1, int diagonals2){
        if(row == this->n_origin){
            generateAns();
            return;
        }
        int available_pos = ((1 << this->n_origin) - 1) & (~(colmuns | diagonals1 | diagonals2));
        while(available_pos != 0){
            int pos_bit = available_pos & (-available_pos);
            available_pos = available_pos & (available_pos - 1);
            int pos_int = __builtin_ctz(pos_bit);
            this->current_queen[row] = pos_int;
            recursion(row+1, colmuns | pos_bit, (diagonals1 | pos_bit) >> 1, (diagonals2 | pos_bit) << 1);
            this->current_queen[row] = -1;
        }
    }
    void generateAns(){
        vector<string> temp;
        for(int i = 0; i < this->n_origin; i++){
            string temp_str;
            temp_str.resize(this->n_origin, '.');
            temp_str[this->current_queen[i]] = 'Q';
            temp.push_back(temp_str);
        }
        this->ans.push_back(temp);
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
    }
}