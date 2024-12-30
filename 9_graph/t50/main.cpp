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
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    res++;
                    queue<pair<int,int>> last_pos;
                    last_pos.push(make_pair(i,j));
                    grid[i][j] = 0;
                    while(!last_pos.empty()){
                        int length = last_pos.size();
                        for(int k = 0; k < length; k++){
                            pair<int,int> pos = last_pos.front();
                            last_pos.pop();
                            int pos_i = pos.first, pos_j = pos.second;
                            if(pos_i - 1 >= 0 && grid[pos_i - 1][pos_j] == '1'){
                                last_pos.push(make_pair(pos_i - 1,pos_j));
                                grid[pos_i - 1][pos_j] = '0';
                            } 
                            if(pos_j - 1 >= 0 && grid[pos_i][pos_j - 1] == '1'){
                                last_pos.push(make_pair(pos_i,pos_j - 1));
                                grid[pos_i][pos_j - 1] = '0';
                            } 
                            if(pos_i + 1 < m && grid[pos_i + 1][pos_j] == '1'){
                                last_pos.push(make_pair(pos_i + 1,pos_j));
                                grid[pos_i + 1][pos_j] = '0';
                            } 
                            if(pos_j + 1 < n && grid[pos_i][pos_j + 1] == '1'){
                                last_pos.push(make_pair(pos_i,pos_j + 1));
                                grid[pos_i][pos_j + 1] = '0';
                            } 
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution A;
    cout << A.numIslands(grid) << endl;;
}

// unordered_set<char*> edge_pos;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << i << "," << j << ":";
        //         if(grid[i][j] == '1'){
        //             char *temp = &grid[i][j];
        //             if(edge_pos.find(temp) == edge_pos.end()){
        //                 res++;
        //                 cout << "new one,";
        //             }
        //             else{
        //                 edge_pos.erase(temp);
        //                 cout << "old one,";
        //             }
        //             if(i + 1 < m){
        //                 char *temp_down = &grid[i+1][j];
        //                 edge_pos.emplace(temp_down);
        //             }
        //             if(j + 1 < n){
        //                 char *temp_right = &grid[i][j+1];
        //                 if(edge_pos.find(temp_right) != edge_pos.end()){
        //                     if(grid[i][j+1] == '1'){
        //                         res--;
        //                         j++;
        //                         cout << "merge";
        //                     }
        //                 }
        //                 else{
        //                     edge_pos.emplace(temp_right);
        //                 }
        //             }
        //         }
        //         cout << endl;
        //     }
        // }