#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int, int>> nodes;
        int ans = 0, i, j, ci, cj, k, ni, nj;
        for(i = 0; i < m; ++i) {
            for(j = 0; j < n; ++j) {
                if(grid[i][j] == '0') continue;
                ++ans;
                nodes.push_back(make_pair(i, j));
                grid[i][j] = '0';
                while(!nodes.empty()) {
                    ci = nodes.front().first;
                    cj = nodes.front().second;
                    nodes.pop_front();
                    for(k = 0; k < 4; ++k) {
                        ni = ci + direction[0][k];
                        nj = cj + direction[1][k];
                        if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                            nodes.push_back(make_pair(ni, nj));
                            grid[ni][nj] = '0';
                        }
                    }   
                }
            }
        }
        return ans;
    }
private:
    int direction[2][4] = {
        {0,1,0,-1},
        {1,0,-1,0}
    };
};

int main(){
    Solution A;
    cout << A.numIslands(grid) << endl;;
}