#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> matrix{{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool first_col_has_zero = false;
        bool first_row_has_zero = false;
        for(int i = 0; i < m && !first_col_has_zero; ++i) {
            if(!matrix[i][0])   first_col_has_zero = true;
        }
        for(int j = 0; j < n && !first_row_has_zero; ++j) {
            if(!matrix[0][j])   first_row_has_zero = true;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i) {
            if(!matrix[i][0]) {
                for(int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < n; ++j) {
            if(!matrix[0][j]) {
                for(int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(first_col_has_zero) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if(first_row_has_zero) {
            for(int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main(){
    for(auto len : matrix){
        for(auto ele : len){
            cout << ele << "\t";
        }
        cout << endl;
    }
    cout << endl;
    Solution A;
    A.setZeroes(matrix);
    for(auto len : matrix){
        for(auto ele : len){
            cout << ele << "\t";
        }
        cout << endl;
    }
}