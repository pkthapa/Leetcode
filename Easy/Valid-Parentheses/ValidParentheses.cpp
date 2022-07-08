#include "main.hpp"

class Solution {
public:
    bool isValid(string s) {
        int sLen = s.length();

        stack<char> stk;
        
        for (int i{0}; i < sLen; ++i){
            if (s[i] == '{' or s[i] == '[' or s[i] == '('){
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