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
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        if(target < matrix[0][0] || target > matrix[m][n])
            return false;
        bool ans = false;
        int i = 0, j = n;
        while(i <= m && j >= 0) {
            if(matrix[i][j] == target) {
                ans = true;
                break;
            }
            else if(matrix[i][j] > target) {
                --j;
            }
            else {
                ++i;
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    bool res = A.searchMatrix(matrix, target);
    cout << res << endl;
}