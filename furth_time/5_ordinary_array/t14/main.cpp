#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<vector<int>> intervals{{1,3},{8,10},{15,18},{2,6}};
vector<vector<int>> intervals{{1,4},{2,3}};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0])    return a[1] < b[1];
            return a[0] < b[0];
        });
        int length = intervals.size();
        ans.emplace_back(intervals[0]);
        for(int i = 1; i < length; ++i) {
            if(intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.emplace_back(intervals[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    vector<vector<int>> res = A.merge(intervals);
    for(auto i : res){
        cout << "[" << i[0] << "," << i[1] << "] ";
    }
    cout << endl;
}