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
        if(this->min_stack.empty()){
            this->min_stack.push(val);
        }
        else{
            int last_min = this->min_stack.top();
            if(val < last_min) last_min = val;
            this->min_stack.push(last_min);
        }
    }
    
    void pop() {
        this->data.pop();
        this->min_stack.pop();
    }
    
    int top() {
        return this->data.top();
    }
    
    int getMin() {
        return this->min_stack.top();
    }
private:
    stack<int> data;
    stack<int> min_stack;
};

int main(){
    // Solution A;
    // auto res =  A.isValid(s);
    // cout << res << endl;
}