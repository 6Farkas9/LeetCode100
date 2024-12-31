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
        int m = matrix.size();
        int n = matrix[0].size() - 1;
        int row;
        for(row = 0; row < m; row++){
            if(matrix[row][0] <= target && target <= matrix[row][n]) break;
        }
        if(row >= m) return false;
        int i = 0,j = n;
        int mid;
        while(i <= j){
            mid = (i + j) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return false;
    }
};

int main(){
    Solution A;
    auto res =  A.searchMatrix(matrix, target);
    cout << res << endl;
}