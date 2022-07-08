#include "main.hpp"

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> m;

    for (auto c : s){
      ++m[c];
    }

    for (int i = 0; i < s.size(); ++i){
      if (m[s[i]] == 1){
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution sln;

  assert(0 == sln.firstUniqChar("leetcode"));
  assert(2 == sln.firstUniqChar("loveleetcode"));
  assert(-1 == sln.firstUniqChar("aabb"));

  return 0;
}