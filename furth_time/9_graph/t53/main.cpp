#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> grid;
        buildGrid(grid, prerequisites);
        vector<int> visited(numCourses, 0);
        for(auto &_pair : grid) {
            if(!visited[_pair.first]) {
                if(!visit(_pair.first, visited, grid))
                    return false;
            }
        }
        return true;
    }
private:
    bool visit(int c_pos, vector<int> &visited, unordered_map<int, unordered_set<int>> &grid) {
        if(visited[c_pos] == 1) return false;
        visited[c_pos] = 1;
        for(auto & n_pos : grid[c_pos]) {
            if(visited[n_pos] != 2) {
                if(!visit(n_pos, visited, grid))    return false;
            }
        }
        visited[c_pos] = 2;
        return true;
    }

    void buildGrid(unordered_map<int, unordered_set<int>> &grid, vector<vector<int>>& prerequisites) {
        for(auto & _pair : prerequisites) {
            if(grid.find(_pair[0]) == grid.end())
                grid[_pair[0]] = unordered_set<int>();
            grid[_pair[0]].insert(_pair[1]);
        }
    }
};

int main(){
    Solution A;
    // cout << A.canFinish(grid) << endl;;
}