#include "main.hpp"

// TC: O(N), N is the length of 's'.
// SC: O(1)
/*
Algorithm:

1. Create a helper function checkPalindrome that takes a string s, and two pointers i and j. This function returns a boolean indicating if s.substring(i, j) is a palindrome.

2. Initialize two pointers, i = 0 and j = s.length() - 1.

3. While i < j, check if the characters at indices i and j match. If they don't, that means we must spend our deletion on one of these characters. Try both options using checkPalindrome. In other words, return true if either checkPalindrome(s, i, j - 1) or checkPalindrome(s, i + 1, j) is true.

4. If we exit the while loop, that means the original string is a palindrome. Since we didn't need to use the deletion, we should return true.
*/
class Solution {
    bool checkPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(const string& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return checkPalindrome(s, l + 1, r) || checkPalindrome(s, l, r - 1);
            }
            ++l;
            --r;
        }
        return true;
    }
};

int main() {
    assert(true == Solution().validPalindrome("aba"));

    assert(true == Solution().validPalindrome("abca"));

    assert(false == Solution().validPalindrome("abc"));

    assert(true == Solution().validPalindrome("deee"));

    assert(true == Solution().validPalindrome("cbbcc"));

    return 0;
}