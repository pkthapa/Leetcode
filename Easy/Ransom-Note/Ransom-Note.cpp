#include "main.hpp"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freqs;

        // Store the character count frequencies.
        for (auto c : magazine) {
            ++freqs[c];
        }

        // Check if the hash-table has all the required characters to
        // construct 'ransomNote'.
        for (auto c : ransomNote) {
            if (freqs[c] <= 0) {
                return false;
            }
            --freqs[c];
        }
        return true;
    }
};

int main() {
    Solution sln;
    {
        string ransomNote = "a";
        string magazine = "b";
        assert(false == sln.canConstruct(ransomNote, magazine));
    }
    {
        string ransomNote = "aa";
        string magazine = "ab";
        assert(false == sln.canConstruct(ransomNote, magazine));
    }
    {
        string ransomNote = "aa";
        string magazine = "aab";
        assert(true == sln.canConstruct(ransomNote, magazine));
    }
    return 0;
}