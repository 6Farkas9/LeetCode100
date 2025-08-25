#include <iostream>
#include <vector>

using namespace std;

// vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
// vector<vector<int>> matrix{{1}};
vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int half_n = n / 2;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < half_n; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

int main(){
    Solution A;
    A.rotate(matrix);
    for(auto len : matrix){
        for(auto ele : len){
            cout << ele << " ";
        }
        cout << endl;
    }
}