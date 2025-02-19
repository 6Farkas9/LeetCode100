#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int pre_num = prerequisites.size();
        if(pre_num == 0) return true;
        for(int i = 0; i < pre_num; i++){
            int pre = prerequisites[i][1];
            int aft = prerequisites[i][0];
            if(pre == aft) return false;
            visited[pre] = 0;
            visited[aft] = 0;
            graph[aft].emplace(pre);
        }
        for(auto point : visited){
            if(!point.second){
                if(!dfs(point.first)) return false;
            }
        }
        return true;
    }
private:
    unordered_map<int,unordered_set<int>> graph;
    unordered_map<int,int> visited;
    bool dfs(int pos){
        visited[pos] = 1;
        for(int val : graph[pos]){
            if(visited[val] == 0){
                if(!dfs(val)) return false;
            }
            else if(visited[val] == 1)
                return false;
        }
        visited[pos] = 2;
        return true;
    }
};

int main(){
    Solution A;
    // cout << A.canFinish(grid) << endl;;
}