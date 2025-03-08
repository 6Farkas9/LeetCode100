#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
// vector<vector<int>> intervals{{1,4},{2,3}};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int length = intervals.size();
        
        quickSort(intervals, 0, length - 1);

        vector<vector<int>> ans;
        int l_p = 0;
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
private:
    void quickSort(vector<vector<int>> &intervals, int start, int end){
        if(start >= end)    return;
        int first = intervals[start][0];
        int second = intervals[start][1];
        int i = start, j = end;
        while(i < j){
            while(i < j && (intervals[j][0] > first || (intervals[j][0] == first && intervals[j][1] >= second))){
                --j;
            }
            if(i >= j)  break;
            intervals[i][0] = intervals[j][0];
            intervals[i][1] = intervals[j][1];
            ++i;
            while(i < j && (intervals[i][0] < first || (intervals[i][0] == first && intervals[i][1] <= second))){
                ++i;
            }
            if(i >= j)  break;
            intervals[j][0] = intervals[i][0];
            intervals[j][1] = intervals[i][1];
            --j;
        }
        intervals[i][0] = first;
        intervals[i][1] = second;
        quickSort(intervals, start, i - 1);
        quickSort(intervals, i + 1, end);
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