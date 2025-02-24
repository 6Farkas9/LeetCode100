#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','A','D','E'}
};

string word = "CCD";

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int length = word.size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == word[0] && recursion(board, word, i, j, 1, m, n, length)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int direction[2][4] = {
        {-1, 0, 1, 0},
        {0, 1, 0, -1}
    };
    bool recursion(vector<vector<char>>& board, string word, int i, int j, int pos,int &m, int &n, int &len){
        if(pos == len){
            return true;
        }
        for(int k = 0; k < 4; ++k){
            int ni = i + this->direction[0][k];
            int nj = j + this->direction[1][k];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == word[pos]){
                char temp = board[i][j];
                board[i][j] = ' ';
                if(recursion(board, word, ni, nj, pos + 1, m, n, len))  return true;
                board[i][j] = temp;
            }
        }
        return false;
    }
};

int main(){
    Solution A;
    cout << A.exist(board, word) << endl;
    
}