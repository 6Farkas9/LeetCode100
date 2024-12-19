#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
vector<vector<int>> intervals{{1,4},{2,3}};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        int start_t,end_t;
        for(int i=0; i<intervals.size(); i++){
            start_t = intervals[i][0];
            end_t = intervals[i][1];
            while(i < intervals.size()-1 && !(intervals[i+1][0] > end_t)){
                start_t = min(intervals[i+1][0],start_t);
                end_t = max(intervals[i+1][1],end_t);
                i++;
            }
            res.push_back(vector<int>{start_t,end_t});
        }
        return res;
    }
private:
    static bool cmp(const vector<int>& x, const vector<int>& y){
        if(x[0] == y[0]){
            return x[1] < y[1];
        }
        return x[0] < y[0];
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