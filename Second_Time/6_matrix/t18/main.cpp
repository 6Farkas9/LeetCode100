#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> matrix{{1,1,2,0},{3,0,5,2},{1,3,1,5}};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col0_0 = false;
        for(int i = 0; i < m; ++i){
            if(!matrix[i][0]){
                col0_0 = true;
            }
            for(int j = 1; j < n; ++j){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = m - 1; i >= 0; --i){
            for(int j = 1; j < n; ++j){
                if(!matrix[i][0] || !matrix[0][j])  matrix[i][j] = 0;
            }
            if(col0_0) matrix[i][0] = 0;
        }
    }
};

int main(){
    for(auto len : matrix){
        for(auto ele : len){
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
    Solution A;
    A.setZeroes(matrix);
    for(auto len : matrix){
        for(auto ele : len){
            cout << ele << " ";
        }
        cout << endl;
    }
}