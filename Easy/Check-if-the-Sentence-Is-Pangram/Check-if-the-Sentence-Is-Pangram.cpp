#include "main.hpp"

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen;
        
        for (auto c : sentence) {
            seen.insert(c);
            
            // Check the size of 'seen' everytime to prevent
            // traversing the whole sentence characters.
            // E.g. for a sentence of 1M characters, what if the first
            // 26 characters are a....z, then in this case we end
            // up saving other iterations to determine if the given
            // sentence is pangram or not.
            if (seen.size() == 26) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sln;
    {
        string sentence = "thequickbrownfoxjumpsoverthelazydog";
        assert(true == sln.checkIfPangram(sentence));
    }
    {
        string sentence = "leetcode";
        assert(false == sln.checkIfPangram(sentence));
    }
    return 0;
}