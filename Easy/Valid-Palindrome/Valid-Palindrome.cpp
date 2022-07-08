#include "main.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (!isalnum(s[l])) { // Is left character is not alpha-num?
                ++l;
            }
            else if (!isalnum(s[r])) { // Is right character is not alpha-num?
                --r;
            }
            else if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            else {
                ++l;
                --r;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;

    assert(true == sln.isPalindrome("aba"));
    
    assert(true == sln.isPalindrome(" "));

    assert(true == sln.isPalindrome("A man, a plan, a canal: Panama"));

    assert(false == sln.isPalindrome("race a car"));

    return 0;
}
