#include "main.hpp"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> Tcount;

        // Let's keep the count of all characters in 't'.
        for (auto c : t) {
            ++Tcount[c];
        }
        
        int i = 0;
        int j = 0;
        
        // No of characters in 't' that must be in 's'.
        int counter = t.size();

        int minStart = 0;
        int minLen = INT32_MAX;
        
        while (j < s.size()) {
            // If character in 's' exists in 't', then decrease.
            if (Tcount[s[j]] > 0) {
                --counter;
            }
            
            --Tcount[s[j]];
            
            ++j;
            
            // When window is found, then move 'i' to find smaller window.
            while (counter == 0) {
                if (j - i < minLen) {
                    minStart = i;
                    minLen = j - i;
                }
                
                ++Tcount[s[i]];
                
                if (Tcount[s[i]] > 0) {
                    ++counter;
                }
                ++i;
            }
        }
        
        if (minLen != INT32_MAX) {
            return s.substr(minStart, minLen);
        }
        return {};
    }
};

int main() {
    Solution sln;
    {
        string s {"ADOBECODEBANC"};
        string t {"ABC"};
        assert("BANC" == sln.minWindow(s, t));
    }
    {
        string s {"a"};
        string t {"a"};
        assert("a" == sln.minWindow(s, t));
    }
    {
        string s {"a"};
        string t {"aa"};
        assert("" == sln.minWindow(s, t));
    }
    return 0;
}