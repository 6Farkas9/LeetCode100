#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s = "";

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        if(length == 0){
            return 0;
        }
        int i = 0;
        int j = i + 1;
        string temp_str = s.substr(i,1);
        cout << temp_str << endl;
        int res = 1;
        while(i<length && j<length){
            int pos = temp_str.find(s[j]);
            if(pos == -1){
                temp_str = temp_str + s[j];
            }
            else{
                res = max(res,int(temp_str.size()));
                i = i + pos + 1;
                temp_str = s.substr(i,j-i+1);
            }
            j++;
        }
        res = max(res,int(temp_str.size()));
        return res;
    }
};

int main(){
    Solution A;
    int res = A.lengthOfLongestSubstring(s);
    cout << res << endl;
}