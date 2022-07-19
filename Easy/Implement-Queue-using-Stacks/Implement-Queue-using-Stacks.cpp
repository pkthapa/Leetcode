#include "main.hpp"

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
        // Not required though, but let's keep them :)
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void push(int x) {
        s1.push(x); // Always push into 's1'.
    }

    int pop() {
        if (!s2.empty()) {
            auto res = s2.top();
            s2.pop();
            return res;
        }
        else {
            // 1. Transfer all 's1' data to 's2'.
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            auto res = s2.top();
            s2.pop();
            return res;
        }
    }

    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        else {
            // 1. Transfer all 's1' data to 's2'.
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    bool empty() {
        return (s1.empty() and s2.empty());
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue sln;
    assert(true == sln.empty());
    sln.push(2);
    sln.push(1);
    sln.push(4);
    assert(2 == sln.peek());
    sln.pop();
    assert(1 == sln.peek());
    sln.pop();
    sln.pop();
    assert(true == sln.empty());
    return 0;
}