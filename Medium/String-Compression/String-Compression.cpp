#include "main.hpp"

class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int i = 0; // Points to the offset which needs to be updated.
        int j = 0; // Counts the character repeatition.
        
        while (i < chars.size()) {
            // Keep moving forward until different character is found.
            while (j < chars.size() && chars[j] == chars[i]) {
                ++j;
            }
            
            // Another character found.
            chars[idx++] = chars[i];

            if (j - i > 1) {
                string s = std::to_string(j - i);
                
                for (auto c : s) {
                    chars[idx++] = c;
                }
            }
            i = j;
        }
        return idx;
    }
};

int main() {
    Solution sln;
    {
        vector<char> chars {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        vector<char> result {'a', '2', 'b', '2', 'c', '3'};
        assert(6 == sln.compress(chars));

        for (auto i = 0; i < result.size(); ++i) {
            assert(chars[i] == result[i]);
        }
    }
    {
        vector<char> chars {'a'};
        vector<char> result {'a'};
        assert(1 == sln.compress(chars));

        for (auto i = 0; i < result.size(); ++i) {
            assert(chars[i] == result[i]);
        }
    }
    {
        vector<char> chars {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        vector<char> result {'a', 'b', '1', '2'};
        assert(4 == sln.compress(chars));

        for (auto i = 0; i < result.size(); ++i) {
            assert(chars[i] == result[i]);
        }
    }
    
    return 0;
}