#include "main.hpp"

class Solution {
public:
    /**
     * @brief Using hash table.
     */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<int, int> m1, m2;
        for (auto c : s) {
            ++m1[c];
        }

        for (auto c : t) {
            ++m2[c];
        }

        // If the strings were anagrams, then a character must occur twice.
        // The character occurence count would be perfectly divisible by 2.
        for (auto itr = m1.begin(); itr != m1.end(); ++itr) {
            if (m2.find(itr->first) == m2.end()) {
                return false;
            }
            else {
                if (itr->second != m2[itr->first]) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * @brief Using sort.
     */
    bool isAnagramUsingSort(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t) ? true : false;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;

    assert(true == sln.isAnagram("aba", "baa"));
    assert(true == sln.isAnagramUsingSort("aba", "baa"));

    assert(false == sln.isAnagram("abaa", "baa"));
    assert(false == sln.isAnagramUsingSort("abaa", "baa"));

    assert(true == sln.isAnagram("leet", "teel"));
    assert(true == sln.isAnagramUsingSort("leet", "teel"));

    assert(false == sln.isAnagram("aa", "bb"));
    assert(false == sln.isAnagramUsingSort("aa", "bb"));

    return 0;
}
