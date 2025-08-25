#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> grid = {
    {2,1,1},
    {0,0,1},
    {1,1,1}
};

// vector<vector<int>> grid = {
//     {0,2}
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int, int>> nodes;
        int i, j, k, ni, nj;
        int ans = 0, flash_num = 0, c_num;
        for(i = 0; i < m; ++i) {
            for(j = 0; j < n; ++j) {
                if(grid[i][j] == 2) {
                    nodes.push_back(make_pair(i, j));
                }
                else if(grid[i][j] == 1) {
                    ++flash_num;
                }
            }
        }
        while(flash_num && !nodes.empty()) {
            c_num = nodes.size();
            while(c_num--) {
                i = nodes.front().first;
                j = nodes.front().second;
                nodes.pop_front();
                for(k = 0; k < 4; ++k) {
                    ni = i + direction[0][k];
                    nj = j + direction[1][k];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        --flash_num;
                        nodes.push_back(make_pair(ni, nj));
                    }
                }
            }
            ++ans;
        }
        return flash_num ? -1 : ans;
    }
private:
    int direction[2][4] = {
        {0,1,0,-1},
        {1,0,-1,0}
    };
};

int main(){
    Solution A;
    cout << A.orangesRotting(grid) << endl;;
}

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int res = 0;
//         vector<pair<int,int>> rotted_pos;
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 2){
//                     bfs(grid, i, j, m, n);
//                 }
//             }
//         }
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 1) return -1;
//                 if(grid[i][j] < res)    res = grid[i][j];
//             }
//         }
//         return -res;
//     }
// private:
//     void bfs(vector<vector<int>>& grid, int i, int j, int m, int n){
//         queue<pair<int,int>> last_pos;
//         last_pos.push(make_pair(i,j));
//         int res = -1;
//         unordered_set<int*> visited;
//         visited.emplace(&grid[i][j]);
//         while(!last_pos.empty()){
//             int length = last_pos.size();
//             for(int k = 0; k < length; k++){
//                 pair<int,int> pos = last_pos.front();
//                 last_pos.pop();
//                 int pos_i = pos.first, pos_j = pos.second;
//                 if(pos_i - 1 >= 0)  setValue(&grid[pos_i - 1][pos_j], visited, res, last_pos, pos_i - 1, pos_j);
//                 if(pos_j - 1 >= 0)  setValue(&grid[pos_i][pos_j - 1], visited, res, last_pos, pos_i, pos_j - 1);
//                 if(pos_i + 1 < m)   setValue(&grid[pos_i + 1][pos_j], visited, res, last_pos, pos_i + 1, pos_j);
//                 if(pos_j + 1 < n)   setValue(&grid[pos_i][pos_j + 1], visited, res, last_pos, pos_i, pos_j + 1);
//             }
//             res--;
//         }
//     }
//     void setValue(int *temp, unordered_set<int*> & visited, int res, queue<pair<int,int>> & last_pos, int pos_i, int pos_j){
//         bool has_visit = (visited.find(temp) != visited.end());
//         if((*temp == 1 || *temp < 0) && !has_visit){
//             if(*temp == 1 || res > *temp)  *temp = res;
//             visited.emplace(temp);
//             last_pos.push(make_pair(pos_i,pos_j));
//         }
//     }
// };