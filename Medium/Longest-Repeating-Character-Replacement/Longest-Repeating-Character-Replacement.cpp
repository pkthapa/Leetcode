#include "main.hpp"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int startWindow = 0;
        int endWindow = 0;

        int result = 0;
        int maxFreq = 0;

        vector<int> count(26, 0); // Tracks the alphabet count.
        while (endWindow < s.size()) {
            
            ++count[s[endWindow] - 'A'];
            
            // Get the max frequency count.
            // Check if the recently incremented vector offset has the max frequency count.
            maxFreq = std::max(maxFreq, count[s[endWindow] - 'A']);
            
            int currWindowSize = endWindow - startWindow + 1;
            
            // Check if the replacements are valid.
            if (currWindowSize - maxFreq <= k) {
                result = std::max(result, currWindowSize);
            }
            else {
                --count[s[startWindow] - 'A'];
                ++startWindow;
            }
            ++endWindow;
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        int k = 2;
        string s = "ABAB";
        assert(4 == sln.characterReplacement(s, k));
    }
    {
        int k = 1;
        string s = "AABABBA";
        assert(4 == sln.characterReplacement(s, k));
    }
    {
        int k = 1;
        string s = "AAAABBA";
        assert(5 == sln.characterReplacement(s, k));
    }
    {
        int k = 2;
        string s = "AAAABBA";
        assert(7 == sln.characterReplacement(s, k));
    }
    return 0;
}