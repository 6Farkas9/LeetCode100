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
        this->data.push(val);
        if(this->min_data.empty() || val <= this->min_data.top())
            this->min_data.push(val);
    }
    
    void pop() {
        if(this->data.empty())  return;
        if(!this->min_data.empty() && this->data.top() == this->min_data.top())
            this->min_data.pop();
        this->data.pop();
    }
    
    int top() {
        return this->data.top();
    }
    
    int getMin() {
        return this->min_data.top();
    }
private:
    stack<int> data;
    stack<int> min_data;
};

int main(){
    // Solution A;
    // auto res =  A.isValid(s);
    // cout << res << endl;
}