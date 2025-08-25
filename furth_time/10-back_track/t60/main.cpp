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
        int m = board.size();
        int n = board[0].size();
        int length = word.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(search(i, j, 1, length, board, word, visited, m, n))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
private:
    int direction[2][4] = {
        {0,1,0,-1},
        {1,0,-1,0}
    };
    bool search(int i, int j, int c, int &length, vector<vector<char>>& board, string &word, vector<vector<bool>> &visited, int &m, int &n) {
        if(c >= length) {
            return true;
        }
        int ni, nj;
        char nch = word[c];
        for(int k = 0; k < 4; ++k) {
            ni = i + direction[0][k];
            nj = j + direction[1][k];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == nch && !visited[ni][nj]) {
                visited[ni][nj] = true;
                if(search(ni, nj, c + 1, length, board, word, visited, m, n))
                    return true;
                visited[ni][nj] = false;
            }
        }
        return false;
    }
};

int main(){
    Solution A;
    cout << A.exist(board, word) << endl;
    
}