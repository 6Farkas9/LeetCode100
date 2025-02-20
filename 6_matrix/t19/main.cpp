#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int num = m * n - 1;
        int left_edge = 0, up_edge = 0, right_edge = n - 1, down_edge = m - 1;
        int direction = 0, i = 0, j = 1;
        ans.push_back(matrix[0][0]);
        while(num){
            if(direction == 0){ // 右
                while(j <= right_edge){
                    ans.push_back(matrix[i][j]);
                    --num;
                    ++j;
                }
                --j;
                ++i;
                ++up_edge;
            }
            else if(direction == 1){ // 下
                while(i <= down_edge){
                    ans.push_back(matrix[i][j]);
                    --num;
                    ++i;
                }
                --i;
                --j;
                --right_edge;
            }
            else if(direction == 2){ // 左
                while(j >= left_edge){
                    ans.push_back(matrix[i][j]);
                    --num;
                    --j;
                }
                ++j;
                --i;
                --down_edge;
            }
            else{ // 上
                while(i >= up_edge){
                    ans.push_back(matrix[i][j]);
                    --num;
                    --i;
                }
                ++i;
                ++j;
                ++left_edge;
            }
            direction = (direction + 1) % 4;
        }
        return ans;
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