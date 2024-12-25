#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> matrix{{}};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int raw_n = matrix.size();
        int col_n = matrix[0].size();
        int total_n = raw_n * col_n;
        int num = 0;
        int raw_s = 0,col_s = 0,raw_e = raw_n-1,col_e = col_n-1;
        vector<int> res;
        bool raw_or_col = false,plus_or_sub = false;
        while(num < total_n){
            if(raw_or_col == 0){
                if(plus_or_sub == 0){
                    for(int i = col_s; i <= col_e; i++){
                        res.push_back(matrix[raw_s][i]);
                        num++;
                    }
                    raw_s += 1;
                    raw_or_col = 1;
                }
                else{
                    for(int i = col_e; i >= col_s; i--){
                        res.push_back(matrix[raw_e][i]);
                        num++;
                    }
                    raw_e -= 1;
                    raw_or_col = 1;
                }
            }
            else{
                if(plus_or_sub == 0){
                    for(int i = raw_s; i <= raw_e; i++){
                        res.push_back(matrix[i][col_e]);
                        num++;
                    }
                    col_e -= 1;
                    raw_or_col = 0;
                    plus_or_sub = 1;
                }
                else{
                    for(int i = raw_e; i >= raw_s; i--){
                        res.push_back(matrix[i][col_s]);
                        num++;
                    }
                    col_s += 1;
                    raw_or_col = 0;
                    plus_or_sub = 0;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution A;
    vector<int> res = A.spiralOrder(matrix);
    for(auto val : res){
        cout << val << " ";
    }
    cout << endl;
}