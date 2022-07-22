#include "main.hpp"

class Solution {
public:
    // Credits: https://www.youtube.com/watch?v=s9fokUqJ76A
    void backtrack(int open, int closed, stack<char>& s, int n, vector<string>& result) {
        // Base case.
        if (open == n && closed == n) {
            string temp;
            auto stkTemp = s;
            while (!stkTemp.empty()) {
                temp = stkTemp.top() + temp;
                stkTemp.pop();
            }
            result.push_back(temp);
            return;
        }

        // Keep adding '(' until the count is less than 'n'.
        if (open < n) {
            s.push('(');
            backtrack(open + 1, closed, s, n, result);
            s.pop();
        }

        // Keep adding ')' until the count is less than 'open'.
        if (closed < open) {
            s.push(')');
            backtrack(open, closed + 1, s, n, result);
            s.pop();
        }
    }

    vector<string> generateParenthesis(int n) {
        stack<char> stk;
        vector<string> result;

        backtrack(0, 0, stk, n, result);
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<string> result {"()"};
        assert(result == sln.generateParenthesis(1));
    }
    {
        vector<string> result {"((()))", "(()())", "(())()", "()(())", "()()()"};
        assert(result == sln.generateParenthesis(3));
    }
    return 0;
}