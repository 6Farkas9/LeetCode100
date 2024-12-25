#include <iostream>
#include <vector>

using namespace std;

// vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
// vector<vector<int>> matrix{{1}};
vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        for(int i = 0,current_l = length; current_l > 1; current_l-=2,i++){
            int edge = i + current_l - 1;
            for(int j = i; j < edge; j++){
                int last;
                bool is_first = true;
                for(int c_i = i, c_j = j, k = 0; k < 4; k++){
                    int next_i = c_j;
                    int next_j = length - 1 - c_i;
                    if(is_first){
                        last = matrix[next_i][next_j];
                        matrix[next_i][next_j] = matrix[c_i][c_j];
                        is_first = false;
                    }
                    else{
                        int temp = matrix[next_i][next_j];
                        matrix[next_i][next_j] = last;
                        last = temp;
                    }
                    c_i = next_i;
                    c_j = next_j;
                }
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