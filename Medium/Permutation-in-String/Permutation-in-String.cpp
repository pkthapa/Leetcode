#include "main.hpp"

class Solution {
    bool isPermutation(vector<int>& charCount) {
        for (int i = 0; i < 26; ++i) {
            // If any offset is non-zero, that means we are not there yet.
            if (charCount[i] != 0) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n) {
            return false;
        }

        // Contain only lowercase English letters.
        vector<int> charCount(26, 0);

        // Concept: Sliding window with an idea of anagrams.
        for (int i = 0; i < m; ++i) {
            ++charCount[s1[i] - 'a'];
            --charCount[s2[i] - 'a'];
        }

        if (isPermutation(charCount)) {
            return true;
        }

        for (int i = m; i < n; ++i) {
            --charCount[s2[i] - 'a'];
            ++charCount[s2[i - m] - 'a'];

            if (isPermutation(charCount)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sln;
    {
        string s1 = "ab";
        string s2 = "eidbaooo";
        assert(true == sln.checkInclusion(s1, s2));
    }
    {
        string s1 = "ab";
        string s2 = "eidboaoo";
        assert(false == sln.checkInclusion(s1, s2));
    }
    {
        string s1 = "abcd";
        string s2 = "abc";
        assert(false == sln.checkInclusion(s1, s2));
    }
    return 0;
}