#include "main.hpp"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int cnt = 0;
        bool cntStarted = false; // To track if the last word's length counting has started (true).

        while (--len >= 0){
            if (s[len] != ' '){
                ++cnt;
                cntStarted = true;
                continue; // Do not let the control reach the below "if" statement.
            }
            
            if (cntStarted) break;
        }
        return cnt;
    }
};

int main() {
    Solution sln;

    string s {"Hello World"};
    assert(5 == sln.lengthOfLastWord(s));

    s = "Hello World    ";
    assert(5 == sln.lengthOfLastWord(s));

    s = "a";
    assert(1 == sln.lengthOfLastWord(s));

    s = "";
    assert(0 == sln.lengthOfLastWord(s));

    return 0;
}