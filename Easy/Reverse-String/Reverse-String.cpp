#include "main.hpp"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
};

int main() {
    Solution sln;
    {
        vector<char> v {'h', 'e', 'l', 'l', 'o'};
        vector<char> o {'o', 'l', 'l', 'e', 'h'};
        sln.reverseString(v);
        assert(o == v);
    }
    {
        vector<char> v {'h'};
        vector<char> o {'h'};
        sln.reverseString(v);
        assert(o == v);
    }
    {
        vector<char> v {'h', 'e', 'l', 'p'};
        vector<char> o {'p', 'l', 'e', 'h'};
        sln.reverseString(v);
        assert(o == v);
    }
    return 0;
}