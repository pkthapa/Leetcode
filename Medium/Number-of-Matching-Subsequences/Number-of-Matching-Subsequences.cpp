#include "main.hpp"

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>&& words) {
        int count = 0;
        for (string word : words) {
            int posAtS = -1;
            for (int i = 0; i < word.length(); i++) {
                posAtS = s.find(word[i], ++posAtS);
                if (posAtS == string::npos) {
                    break;
                }
            }
            if (posAtS >= 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sln;
    assert(3 == sln.numMatchingSubseq("abcde", {"a", "bb", "acd", "ace"}));
    assert(1 == sln.numMatchingSubseq("abc", {"a", "bb", "acd", "ace"}));
    assert(0 == sln.numMatchingSubseq("xyz", {"a", "bb", "acd", "ace"}));
    return 0;
}