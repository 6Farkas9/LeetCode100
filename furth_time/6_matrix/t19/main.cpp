#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;
        int i = 0, j = 0;
        while(left <= right && up <= down) {
            // cout << left << "," <<  right << "," <<  up << "," << down << endl;
            while(left <= right && up <= down && j <= right) {
                ans.emplace_back(matrix[i][j]);
                ++j;
            }
            i = ++up, j = right;
            while(left <= right && up <= down && i <= down) {
                ans.emplace_back(matrix[i][j]);
                ++i;
            }
            i = down, j = --right;
            while(left <= right && up <= down && j >= left) {
                ans.emplace_back(matrix[i][j]);
                --j;
            }
            i = --down, j = left;
            while(left <= right && up <= down && i >= up) {
                ans.emplace_back(matrix[i][j]);
                --i;
            }
            i = up, j = ++left;
            // cout << left << "," <<  right << "," <<  up << "," << down << endl;
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