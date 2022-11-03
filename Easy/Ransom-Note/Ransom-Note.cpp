#include "main.hpp"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freqs;

        // Store the character frequecies of 'ransomNote' first
        // to avoid computational costs.
        for (auto c : ransomNote) {
            ++freqs[c];
        }

        // For every character (c) in 'magazine', decrease 'c's frequency count
        // and check if it has reached '0'. If reached '0' then erase 'c' from
        // 'freqs' and then check the size of the 'freqs'. If 'freqs' is empty
        // then that means we are able to construct (return true).
        for (auto c : magazine) {
            if (freqs.count(c) > 0 && --freqs[c] == 0) {
                freqs.erase(c);
                if (freqs.empty()) {
                    return true;
                }
            }
        }
        return false;
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
