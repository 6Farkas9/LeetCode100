#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> matrix{{1,1,2,0},{3,0,5,2},{1,3,1,5}};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int raw_n = matrix.size();
        int col_n = matrix[0].size();
        unordered_set<int> raw,col;
        int i,j;
        for(int i = 0; i < raw_n; i++){
            for(int j = 0; j < col_n; j++){
                if(matrix[i][j] == 0){
                    raw.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto val_i : raw){
            for(j = 0; j < col_n; j++){
                matrix[val_i][j] = 0;
            }
        }
        for(auto val_j : col){
            for(i = 0; i < raw_n; i++){
                matrix[i][val_j] = 0;
            }
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