#include <iostream>
#include <stack>

using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        _data.push(val);
        if(_min_data.empty() || val <= _min_data.top())
            _min_data.push(val);
    }
    
    void pop() {
        if(_min_data.top() == _data.top())
            _min_data.pop();
        _data.pop();
    }
    
    int top() {
        return _data.top();
    }
    
    int getMin() {
        return _min_data.top();
    }
private:
    stack<int> _data;
    stack<int> _min_data;
};


int main(){
    // Solution A;
    // auto res =  A.isValid(s);
    // cout << res << endl;
}