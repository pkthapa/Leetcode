#include "main.hpp"

class Solution {
public:
    string intToRoman(int num) {
	vector<pair<int, string>> mapping = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"}};

        string roman;
        int idx = 0;
        int sz = mapping.size();
        
        while (idx < sz) {
            if (num - mapping[idx].first >= 0) {
                num -= mapping[idx].first;
                roman += mapping[idx].second;
            }
            else {
                ++idx;
            }
        }
        return roman;
    }
};

int main() {
    Solution sln;
    assert("III" == sln.intToRoman(3));
    assert("LVIII" == sln.intToRoman(58));
    assert("MCMXCIV" == sln.intToRoman(1994));
    return 0;
}