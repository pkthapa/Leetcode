#include "main.hpp"

class Solution {
public:
    string reverseWords(string s) {
        string result;

        // Start from the end.
        for (int r = s.size() - 1; r >= 0; --r) {
            // Remove all white-space characters.
            if (s[r] == ' ') {
                continue;
            }

            int t = r;
            while (r >= 0 && s[r] != ' ') {
                r--;
            }
            result += s.substr(r + 1, t - r) + " ";
        }

        // Remove last white space character.
        if (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};

int main() {
    Solution sln;

    assert("blue is sky the" == sln.reverseWords("the sky is blue"));

    assert("world hello" == sln.reverseWords("  hello world  "));

    assert("example good a" == sln.reverseWords("a good   example"));

    return 0;
}