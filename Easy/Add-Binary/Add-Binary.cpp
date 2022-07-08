#include "main.hpp"

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int lenA = a.size() - 1;
        int lenB = b.size() - 1;

        while (lenA >= 0 or lenB >= 0 or carry != 0) {

            if (lenA >= 0) {
                carry += a[lenA] - '0';
                --lenA;
            }

            if (lenB >= 0) {
                carry += b[lenB] - '0';
                --lenB;
            }

            res += std::to_string(carry % 2);
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sln;

    assert("1000" == sln.addBinary("110", "10"));

    assert("10" == sln.addBinary("10", "0"));

    assert("" == sln.addBinary({}, {}));

    return 0;
}