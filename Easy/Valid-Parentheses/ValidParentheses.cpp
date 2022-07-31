#include "main.hpp"

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        // Keep pushing the left side of the brackets into a stack.
        // If it is not left side, then compare the top element with 
        // similar left bracket type and then pop out from the stack.
        for (int i{0}; i < s.length(); ++i) {
            if (s[i] == '{' or s[i] == '[' or s[i] == '(') {
                stk.push(s[i]);
            }
            else if (!stk.empty()){
                if (s[i] == '}' and stk.top() == '{') stk.pop();
                else if (s[i] == ')' and stk.top() == '(') stk.pop();
                else if (s[i] == ']' and stk.top() == '[') stk.pop();
                else return false;
            }
            else{
                return false;
            }
        }
        return stk.empty() ? true : false;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N{0};
    cin >> N;

    string s;
    Solution sln;
    
    while (N-- > 0){
        cin >> s;
        cout << boolalpha << sln.isValid(s) << endl;
    }
    return 0;
}
