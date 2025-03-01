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
        int ans = 0;
        int direction[2][4] = {
            {-1, 0, 1, 0},
            {0, 1, 0, -1}
        };
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '0')   continue;
                queue<pair<int,int>>    nodes;
                nodes.push(make_pair(i,j));
                grid[i][j] = '0';
                ++ans;
                while(!nodes.empty()){
                    auto node = nodes.front();
                    nodes.pop();
                    int ci = node.first, cj = node.second;
                    for(int k = 0; k < 4; ++k){
                        int ni = ci + direction[0][k], nj = cj + direction[1][k];
                        if(ni < 0 || ni >= m || nj < 0 || nj >= n)  continue;
                        if(grid[ni][nj] == '1'){
                            grid[ni][nj] = '0';
                            nodes.push(make_pair(ni, nj));
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    cout << A.numIslands(grid) << endl;;
}