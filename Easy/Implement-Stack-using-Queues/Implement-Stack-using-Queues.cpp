#include "main.hpp"

class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
    }

    int pop() {
        // Copy 'n - 1' elements from 'q' and push them back again to the queue.
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }

        // Pop the last element.
        int ele = q.front();
        q.pop();
        return ele;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    {
        MyStack myStack;
        myStack.push(1);
        myStack.push(2);
        assert(2 == myStack.top());
        assert(2 == myStack.pop());
        assert(false == myStack.empty());
    }
    return 0;
}