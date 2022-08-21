#include "main.hpp"

class Solution {
    int remove(string& str, const string& stamp) {
        for (int i = 0; i < str.size(); ++i) {
            int j = 0;
            int temp = i;
            bool flag = false;

            while (j < stamp.size() && temp < str.size() &&
                  (str[temp] == '*' || str[temp] == stamp[j])) {
                if (str[temp] == stamp[j]) {
                    flag = true;
                }
                ++temp;
                ++j;
            }
            
            if (j == stamp.size() && flag) {
                for (int k = 0; k < stamp.size(); ++k) {
                    str[i + k] = '*';
                }
                return i; // Return start index of replacement.
            }
        }
        return str.size();
    }

public:
    // Let's try the reverse way.
    // stamp = "abca"
    // target = "aabcaca"
    // Approach:
    // 1. Find 'stamp' in 'target' and replace with '*', if found.
    // 2. Repeat the step. '*' can be considered equal to any character.
    // 3. If all the characters are replaced with '*', then it is a valid conversion.
    // "aabcaca" -> "a****ca" -> "*****ca"->"*******"
    vector<int> movesToStamp(string& stamp, string& target) {
        string aim (target.length(), '*');
        string str = target;
        vector<int> answer;

        while (str != aim) {
            int temp = remove(str, stamp);

            if (str.length() == temp) {
                return {};
            }
            answer.emplace_back(temp);
        }
        
        reverse(answer.begin(), answer.end());

        return answer;
    }
};

int main() {
    Solution sln;
    {
        vector<int> result {0, 2};
        string stamp = "abc", target = "ababc";
        assert(result == sln.movesToStamp(stamp, target));
    }
    {
        vector<int> result {3, 0, 1};
        string stamp = "abca", target = "aabcaca";
        assert(result == sln.movesToStamp(stamp, target));
    }
    return 0;
}