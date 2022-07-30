#include "main.hpp"

// Credits: https://www.youtube.com/watch?v=ByQfvU8_fvM&ab_channel=AlgorithmsMadeEasy
class Solution {
    bool isSubset(array<int, 26>& target, array<int, 26>& temp) {
        for (int i = 0; i < 26; ++i) {
            if (target[i] > temp[i]) {
                return false;
            }
        }
        return true;
    }

public:
    // Approach:
    // 1. Merge all the words from 'words2' and maintain the maximum count of every letters in an array.
    // 2. Compare the merged string with every words in 'words1'.
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        array<int, 26> target {0};

        for (auto word : words2) {
            // Holds the max count of every letter in 'words2'.
            array<int, 26> temp {0};

            for (auto c : word) {
                ++temp[c - 'a'];

                // Get the max count of every letter.
                target[c - 'a'] = std::max(target[c - 'a'], temp[c - 'a']);
            }
        }

        // Count the occurences of letters in every words in 'words1'.
        for (auto word : words1) {
            array<int, 26> temp {0};

            for (auto c : word) {
                ++temp[c - 'a'];
            }

            // Include 'word' in the 'result' array.
            if (isSubset(target, temp)) {
                result.emplace_back(word);
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<string> words1 {"amazon", "apple", "facebook", "google", "leetcode"};
        vector<string> words2 {"e", "o"};
        vector<string> result {"facebook", "google", "leetcode"};
        assert(result == sln.wordSubsets(words1, words2));
    }
    {
        vector<string> words1 {"amazon", "apple", "facebook", "google", "leetcode"};
        vector<string> words2 {"l", "e"};
        vector<string> result {"apple", "google", "leetcode"};
        assert(result == sln.wordSubsets(words1, words2));
    }
    return 0;
}