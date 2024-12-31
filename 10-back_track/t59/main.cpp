#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};

string word = "CCD";

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->row_len = board.size();
        this->col_len = board[0].size();
        this->length = word.size();
        vector<vector<bool>> visit(this->row_len,vector<bool>(this->col_len,false));
        for(int i = 0; i < row_len; i++){
            for(int j = 0; j < col_len; j++){
                if(board[i][j] == word[0]){
                    if(recursion(board, word, i, j, 1, visit)) return true;
                }
            }
        }
        return false;
    }
private:
    int row_len,col_len,length;
    int i_plus[4] = {1,0,-1,0};
    int j_plus[4] = {0,1,0,-1};
    bool recursion(vector<vector<char>>& board, string & word, int i, int j, int n, vector<vector<bool>> & visit){
        if(n == this->length) return true;
        visit[i][j] = true;
        char c_str = word[n];
        for(int k = 0; k < 4; k++){
            int next_i = i + this->i_plus[k];
            int next_j = j + this->j_plus[k];
            if(next_i >= 0 && next_i < row_len && next_j >= 0 && next_j < col_len 
                && board[next_i][next_j] == c_str 
                && !visit[next_i][next_j]){
                if(recursion(board, word, next_i, next_j, n+1, visit)) return true;
            }
        }
        visit[i][j] = false;
        return false;
    }
};

int main(){
    Solution A;
    cout << A.exist(board, word) << endl;
    
}