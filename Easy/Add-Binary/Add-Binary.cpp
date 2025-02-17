#include "main.hpp"
// Function prototype
void myStrReverse(string& res);

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int aLen = a.length() - 1, bLen = b.length() - 1;

        while (aLen >= 0 or bLen >= 0 or carry != 0) {
            if (aLen >= 0) {
                carry += a[aLen] - '0';
                --aLen;
            }
            if (bLen >= 0) {
                carry += b[bLen] - '0';
                --bLen;
            }

            res += to_string(carry % 2);
            carry /= 2;
        }

        // std::reverse(res.begin(), res.end());
        myStrReverse(res);
        return res;
    }
};

void myStrReverse(string& res) {
    int i = 0, j = res.length() - 1;
    while (i < j) {
        std::swap(res[i++], res[j--]);
    }
}

int main() {
    Solution sln;

    assert("1000" == sln.addBinary("110", "10"));

    assert("10" == sln.addBinary("10", "0"));

    assert("" == sln.addBinary({}, {}));

    return 0;
}