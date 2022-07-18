#include "main.hpp"

class LongestSubstringKDistinct {
public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        int windowStart = 0;
        unordered_map<char, int> charFreqCount;

        // Start 'windowEnd' from start and move towards the end.
        for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd) {
            char rightChar = str[windowEnd];
            ++charFreqCount[rightChar];

            // Shrink the sliding window, until we are left with 'k' distinct
            // characters in the frequency map.
            while (charFreqCount.size() > k) {
                char leftChar = str[windowStart];
                charFreqCount[leftChar]--;

                if (charFreqCount[leftChar] == 0) {
                    charFreqCount.erase(leftChar);
                }
                windowStart++; // Shrink the window.
            }
            maxLength = std::max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};

int main() {
    LongestSubstringKDistinct sln;
    {
        int k = 2;
        string s = "eceba"; // "ece"
        assert(3 == sln.findLength(s, k));
    }
    {
        int k = 1;
        string s = "aa";
        assert(2 == sln.findLength(s, k));
    }
    {
        int k = 3;
        string s = "cbbebi"; // "cbbeb"
        assert(5 == sln.findLength(s, k));
    }
    return 0;
}