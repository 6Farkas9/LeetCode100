#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n = 2;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->num_left = 0;
        this->num_right = 0;
        recursion(n);
        return this->ans;
    }
private:
    vector<string> ans;
    string current_str;
    int num_left, num_right;
    void recursion(int n){
        if(this->num_left == n && this->num_right == n){
            this->ans.push_back(this->current_str);
            return;
        }
        else{
            if(this->num_left < n){
                this->current_str.push_back('(');
                this->num_left++;
                recursion(n);
                this->num_left--;
                this->current_str.pop_back();
            }
            if(this->num_right < this->num_left){
                this->current_str.push_back(')');
                this->num_right++;
                recursion(n);
                this->num_right--;
                this->current_str.pop_back();
            }
        }
    }
};

int main(){
    Solution A;
    vector<string> res = A.generateParenthesis(n);
    cout << res.size() << endl;
    for(auto val : res){
       cout << val << endl;
    }
}