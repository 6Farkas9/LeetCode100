#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string s = "eccbbbbdecf";

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int length = s.size();
        unordered_map<char, int> last_pos;
        for(int i = 0; i < length; i++) last_pos[s[i]] = i;
        vector<int> ans;
        int right_edge = last_pos[s[0]], left_edge = 0;
        for(int i = 0; i < length; i++){
            if(i == right_edge){
                ans.push_back(right_edge - left_edge + 1);
                cout << left_edge << "," << right_edge << endl;
                int j = i + 1;
                if(j < length){
                    left_edge = j;
                    right_edge = last_pos[s[j]];
                }
            }
            else{
                right_edge = max(last_pos[s[i]], right_edge);
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto ans = A.partitionLabels(s);
    for(auto val : ans) cout << val << " ";
    cout << endl;
}