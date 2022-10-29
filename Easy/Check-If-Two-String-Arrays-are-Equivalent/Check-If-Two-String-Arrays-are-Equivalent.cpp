#include "main.hpp"

class Solution {
public:
    bool arrayStringsAreEqual(const vector<string>& word1, const vector<string>& word2) {
        // Pointers to mark the indices of 'word1' & 'word2'.
        int word1Counter = 0, word2Counter = 0;
        
        // Pointers to mark the character indices of current word pointed by above pointers.
        int word1CharCounter = 0, word2CharCounter = 0;
        
        while (word1Counter < word1.size() && word2Counter < word2.size()) {
            // If the characters at the two string are same, increment the character pointers.
            // Otherwise return false.
            if (word1[word1Counter][word1CharCounter++] != word2[word2Counter][word2CharCounter++]) {
                return false;
            }

            // If the character pointer reaches the end of string in the list word1, 
            // Move to the next string in the list and, reset the character pointer to 0.
            if (word1CharCounter == word1[word1Counter].size()) {
                ++word1Counter;
                word1CharCounter = 0;
            }
            
            // If the character pointer reaches the end of string in the list word2, 
            // Move to the next string in the list and, reset the character pointer to 0.
            if (word2CharCounter == word2[word2Counter].size()) {
                ++word2Counter;
                word2CharCounter = 0;
            }
        }
        // Words in both the lists should be traversed.
        return (word1Counter == word1.size() && word2Counter == word2.size());
    }
};

int main() {
    Solution sln;
    {
        vector<string> word1 {"ab", "c"};
        vector<string> word2 {"a", "bc"};
        assert(true == sln.arrayStringsAreEqual(word1, word2));
    }
    {
        vector<string> word1 {"ab", "c"};
        vector<string> word2 {"abc"};
        assert(true == sln.arrayStringsAreEqual(word1, word2));
    }
    {
        vector<string> word1 {"abc", "d", "defg"};
        vector<string> word2 {"abcddefg"};
        assert(true == sln.arrayStringsAreEqual(word1, word2));
    }
    {
        vector<string> word1 {"abcc", "d", "defg"};
        vector<string> word2 {"abcddefg"};
        assert(false == sln.arrayStringsAreEqual(word1, word2));
    }
    return 0;
}