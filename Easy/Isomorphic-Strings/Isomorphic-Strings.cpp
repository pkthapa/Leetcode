#include "main.hpp"

// Credits: https://www.youtube.com/watch?v=7yF-U1hLEqQ&ab_channel=NeetCode
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapST;
        map<char, char> mapTS;

        for (int i = 0; i < s.size(); ++i) {
            char s1 = s[i];
            char t1 = t[i];

            if ((mapST.count(s1) != 0 && mapST[s1] != t1) ||
                (mapTS.count(t1) != 0 && mapTS[t1] != s1)) {
                return false;
            }
            mapST[s1] = t1;
            mapTS[t1] = s1;
        }
        return true;
    }
};

int main() {
    Solution sln;

    assert(true == sln.isIsomorphic("egg", "add"));

    assert(false == sln.isIsomorphic("foo", "bar"));

    assert(true == sln.isIsomorphic("paper", "title"));

    return 0;
}