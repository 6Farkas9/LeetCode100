#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> matrix = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}
};
int target = 15;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        if(target < matrix[0][0] || target > matrix[m][n])  return false;
        int line;
        for(line = 0; line <= m; ++line){
            if(matrix[line][0] <= target && target <= matrix[line][n])    break;
        }
        if(line > m)   return false;
        int i = 0, j = n, mid;
        while(i <= j){
            mid = (i + j) / 2;
            if(matrix[line][mid] == target) return true;
            else if(matrix[line][mid] > target) j = mid - 1;
            else    i = mid + 1;
        }
        return false;
    }
};

int main(){
    Solution A;
    auto res =  A.searchMatrix(matrix, target);
    cout << res << endl;
}