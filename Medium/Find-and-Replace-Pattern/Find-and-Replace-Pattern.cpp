#include "main.hpp"

class Solution {
public:
    // Idea from https://leetcode.com/submissions/detail/755993468/
    vector<string> findAndReplacePattern(vector<string>&& words, string pattern) {
        vector<string> result;
        unordered_map<char, char> m1, m2;

        for (auto word : words) {

            bool patterMatches = true;
            for (size_t i = 0; i < word.size(); ++i) {
                char c1 = word[i];
                char c2 = pattern[i];

                if ((m1.count(c1) != 0 and m1[c1] != c2) or
                    (m2.count(c2) != 0 and m2[c2] != c1)) {
                    patterMatches = false;
                    break;
                }
                m1[c1] = c2;
                m2[c2] = c1;
            }

            // Clear maps.
            m1.clear(), m2.clear();

            // Collecting result.
            if (patterMatches) {
                result.emplace_back(word);
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<string> expOutput {"mee", "aqq"};
        assert(expOutput == sln.findAndReplacePattern({"abc", "deq", "mee", "aqq", "dkd", "ccc"}, "abb"));
    }
    {
        vector<string> expOutput {"a", "b", "c"};
        assert(expOutput == sln.findAndReplacePattern({"a", "b", "c"}, "a"));
    }
    return 0;
}