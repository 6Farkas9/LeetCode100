#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix{ {1, 2, 3, 4, 5 },
                            {6, 7, 8, 9, 10},
                            {11,12,13,14,15},
                            {16,17,18,19,20},
                            {21,22,23,24,25}};
int target = 1;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        if(target > matrix[m][n] || target < matrix[0][0])  return false;
        int i = 0, j = n;
        while(i <= m && j >= 0){
            if(target == matrix[i][j])  return true;
            else if(target > matrix[i][j])  i++;
            else    j--;
        }
        return false;
    }
};

int main(){
    Solution A;
    bool res = A.searchMatrix(matrix, target);
    cout << res << endl;
}