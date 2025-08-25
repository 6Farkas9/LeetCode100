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
int target = 11;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1])  return false;
        int i = 0, j = n - 1, mid;
        for(int l = 0; l < m; ++l) {
            if(matrix[l][j] < target)
                continue;
            while(i <= j) {
                mid = (i + j) / 2;
                if(matrix[l][mid] == target)    return true;
                else if(matrix[l][mid] > target)    j = mid - 1;
                else i = mid + 1;
            }
            break;
        }
        return false;
    }
};

int main(){
    Solution A;
    auto res =  A.searchMatrix(matrix, target);
    cout << res << endl;
}