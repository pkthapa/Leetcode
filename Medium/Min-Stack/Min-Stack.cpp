#include "main.hpp"

#if 0
class MinStack {
public:
    int minNum = INT64_MAX; // Holds the minimum data.
    stack<int> stk; // Internal stack to hold the data.

    MinStack() {
        stk = stack<int>(); // Initialize the internal stack.
    }
    
    void push(int val) {
        if (stk.empty()) {
            minNum = val;
        }
        
        if (val >= minNum) {
            stk.push(val);
        }
        else {
            stk.push(2 * val - minNum); // Logic: minNum is always greater on this line. Subtracting will give -ve result always.
            minNum = val;
        }
    }
    
    void pop() {
        if (stk.empty()) {
            return;
        }

        if (stk.top() < minNum) {
            minNum = 2 * minNum - stk.top();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minNum;
    }
};
#endif

class MinStack {
public:
    int32_t minNum = INT32_MAX; // To hold the minimum data.
    stack<pair<int, int>> stk; // Internal stack to hold the data. stack <current value, minimum value>.

    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            stk.push(make_pair(val, val));
            return;
        }

        auto top = stk.top();
        if (val > top.second) {
            stk.push(make_pair(val, top.second));
        }
        else {
            stk.push(make_pair(val, val));
        }
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    {
        MinStack mStk;
        mStk.push(-2);
        mStk.push(0);
        mStk.push(-3);
        assert(-3 == mStk.getMin());
        assert(-3 == mStk.top());
        mStk.pop();
        assert(-2 == mStk.getMin());
        assert(0 == mStk.top());
    }
    {
        MinStack mStk;
        mStk.push(-2);
        mStk.push(INT32_MIN);
        mStk.push(-3);
        assert(INT32_MIN == mStk.getMin());
        assert(-3 == mStk.top());
        mStk.pop();
        assert(INT32_MIN == mStk.getMin());
        assert(INT32_MIN == mStk.top());
    }
    return 0;
}