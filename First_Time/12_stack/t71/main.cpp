#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> temperatures = {73,74,75,71,69,72,76,73};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> not_found;
        int length = temperatures.size();
        not_found.push(0);
        vector<int> ans(length, 0);
        for(int i = 1; i < length; i++){
            cout << i << endl;
            int current_t = temperatures[i];
            while(!not_found.empty() && current_t > temperatures[not_found.top()]){
                cout << "ans[" << not_found.top() << "]:" << i - not_found.top() << endl;
                ans[not_found.top()] = i - not_found.top();
                not_found.pop();
            }
            not_found.push(i);
        }
        return ans;
    }
};

int main(){
    Solution A;
    auto res =  A.dailyTemperatures(temperatures);
    for(auto val : res) cout << val << " ";
    cout << endl;
}