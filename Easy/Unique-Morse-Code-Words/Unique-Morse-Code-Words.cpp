#include "main.hpp"

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCodes {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> concatenatedWords;
        for (auto word : words) {
            string str;
            for (auto c : word) {
                str += morseCodes[c - 'a'];
            }
            concatenatedWords.insert(str);
        }

        return concatenatedWords.size();
    }
};

int main() {
    Solution sln;
    {
        vector<string> words {"gin", "zen", "gig", "msg"};
        assert(2 == sln.uniqueMorseRepresentations(words));
    }
    {
        vector<string> words {"a"};
        assert(1 == sln.uniqueMorseRepresentations(words));
    }
    return 0;
}