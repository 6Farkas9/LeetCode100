#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sk;
        int length = temperatures.size();
        vector<int> ans(length, 0);
        for(int i = 0; i < length; ++i) {
            if(sk.empty()) {
                sk.push(i);
            }
            else {
                if(temperatures[i] <= temperatures[sk.top()]) {
                    sk.push(i);
                }
                else {
                    while(!sk.empty() && temperatures[i] > temperatures[sk.top()]) {
                        ans[sk.top()] = i - sk.top();
                        sk.pop();
                    }
                    sk.push(i);
                }
            }
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