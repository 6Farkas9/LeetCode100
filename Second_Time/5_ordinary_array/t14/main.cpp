#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
// vector<vector<int>> intervals{{1,4},{2,3}};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0])    return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int length = intervals.size(), l_p = 0;
        int start_n, end_n;
        while(l_p < length){
            start_n = intervals[l_p][0];
            end_n = intervals[l_p][1];
            while(l_p < length && intervals[l_p][0] <= end_n){
                end_n = max(end_n, intervals[l_p][1]);
                ++l_p;
            }
            ans.push_back(vector<int>{start_n, end_n});
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