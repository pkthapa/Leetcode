#include "main.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int maxCount = 0;
        unordered_set<char> us;
        int startWindow = 0;

        // Sliding window approach.
        for (int endWindow = 0; endWindow < s.size(); ++endWindow) {
            // If 's[endWindow]' is present in 'us', then try removing all the elements before 's[endWindow]'
            // until duplicate is removed. We do by shrinking the window size (incrementing 'startWindow').
            while (us.count(s[endWindow]) > 0) {
                us.erase(s[startWindow]);
                ++startWindow;
            }

            us.insert(s[endWindow]);
            maxCount = std::max(maxCount, endWindow - startWindow + 1);
        }
        return maxCount;
    }
};

int main() {
    Solution sln;
    assert(3 == sln.lengthOfLongestSubstring("abcabcbb"));
    assert(1 == sln.lengthOfLongestSubstring("bbbbb"));
    assert(3 == sln.lengthOfLongestSubstring("pwwkew"));
    assert(3 == sln.lengthOfLongestSubstring("vdvf"));
    return 0;
}