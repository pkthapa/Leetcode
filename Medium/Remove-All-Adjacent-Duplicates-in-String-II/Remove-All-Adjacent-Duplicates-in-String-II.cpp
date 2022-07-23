#include "main.hpp"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Vector of pair of character and its frequency count.
        vector<pair<char, int>> vect;

        for (auto c : s) {
            if (vect.empty() || vect.back().first != c) {
                vect.push_back({c, 0});
            }

            // If 'k' count matches, then remove the last entry.
            if (++vect.back().second == k) {
                vect.pop_back();
            }
        }

        string result;
        for (const auto& i : vect) {
            result += string(i.second, i.first);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        string s = "abcd";
        int k = 2;
        assert("abcd" == sln.removeDuplicates(s, k));
    }
    {
        string s = "deeedbbcccbdaa";
        int k = 3;
        assert("aa" == sln.removeDuplicates(s, k));
    }
    {
        string s = "pbbcggttciiippooaais";
        int k = 2;
        assert("ps" == sln.removeDuplicates(s, k));
    }
    return 0;
}