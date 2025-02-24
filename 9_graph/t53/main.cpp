#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto pair : prerequisites){
            graph[pair[0]].emplace_back(pair[1]);
        }
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; ++i){
            if(visited[i] == 0){
                if(!dfs(graph, visited, i)) return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int node){
        visited[node] = 1;
        int length = graph[node].size();
        for(int i = 0; i < length; ++i){
            int next = graph[node][i];
            if(visited[next] == 1)    return false;
            if(visited[next] == 0){
                if(!dfs(graph, visited, next))  return false;
            }
        }
        visited[node] = 2;
        return true;
    }
};

int main(){
    Solution A;
    // cout << A.canFinish(grid) << endl;;
}