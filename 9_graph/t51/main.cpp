#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> grid = {
    {2,1,1},
    {1,1,0},
    {0,1,1}
};

// vector<vector<int>> grid = {
//     {0,2}
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> rotted_pos;
        int orange_num = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    rotted_pos.push(make_pair(i,j));
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == 0) grid[i][j] = -1;
                else{
                    grid[i][j] = -2;
                    orange_num++;
                }
            }
        }
        if(orange_num == 0) return 0;
        int res = 0;
        while(!rotted_pos.empty()){
            int length = rotted_pos.size();
            for(int i = 0; i < length; i++){
                pair<int,int> pos = rotted_pos.front();
                rotted_pos.pop();
                for(int j = 0; j < 4; j++){
                    int next_i = pos.first + this->i_plus[j];
                    int next_j = pos.second + this->j_plus[j];
                    if(next_i < m && next_i >=0 && next_j < n && next_j >= 0 && grid[next_i][next_j] == -2){
                        int temp = grid[pos.first][pos.second] + 1;
                        grid[next_i][next_j] = temp;
                        if(temp > res) res = temp;
                        rotted_pos.push(make_pair(next_i,next_j));
                        orange_num--;
                    }
                }
            }
        }
        if(orange_num > 0) return -1;
        else return res;
    }
private:
    int i_plus[4] = {-1,0,1,0};
    int j_plus[4] = {0,-1,0,1};
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