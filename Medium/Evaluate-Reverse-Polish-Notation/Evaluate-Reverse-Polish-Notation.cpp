#include "main.hpp"

class Solution {
public:
    // Keeping pushing digits to the stack.
    // When operator is found, then perform operation on the last two digits, pop them and
    // push the result in the stack.
    // After processing all tokens, return the top of the stack.
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (auto token : tokens) {
            if (token == "+") {
                auto rightOperand = stk.top();
                stk.pop();
                auto leftOperand = stk.top();
                stk.pop();
                stk.push(leftOperand + rightOperand);
            }
            else if ("-" == token) {
                auto rightOperand = stk.top();
                stk.pop();
                auto leftOperand = stk.top();
                stk.pop();
                stk.push(leftOperand - rightOperand);
            }
            else if ("*" == token) {
                auto rightOperand = stk.top();
                stk.pop();
                auto leftOperand = stk.top();
                stk.pop();
                stk.push(leftOperand * rightOperand);
            }
            else if ("/" == token) {
                auto rightOperand = stk.top();
                stk.pop();
                auto leftOperand = stk.top();
                stk.pop();
                stk.push(leftOperand / rightOperand);
            }
            else { // It is a digit.
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};

int main() {
    Solution sln;
    {
        vector<string> token {"2", "1", "+", "3", "*"};
        assert(9 == sln.evalRPN(token));
    }
    {
        vector<string> token {"4", "13", "5", "/", "+"};
        assert(6 == sln.evalRPN(token));
    }
    {
        vector<string> token {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        assert(22 == sln.evalRPN(token));
    }
    return 0;
}