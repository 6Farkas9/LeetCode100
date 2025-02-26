#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> ans(length--);
        stack<int> not_found;
        for(int i = 0; i <= length; ++i){
            if(!not_found.empty() && temperatures[i] > temperatures[not_found.top()]){
                while(!not_found.empty() && temperatures[i] > temperatures[not_found.top()]){
                    ans[not_found.top()] = i - not_found.top();
                    not_found.pop();
                }
            }
            if(i < length){
                if( temperatures[i] < temperatures[i + 1]) ans[i] = 1;
                else    not_found.push(i);
            }
        }
        while(!not_found.empty()){
            ans[not_found.top()] = 0;
            not_found.pop();
        }
        ans[length] = 0;
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.dailyTemperatures(temperatures);
    for(auto val : res) cout << val << " ";
    cout << endl;
}