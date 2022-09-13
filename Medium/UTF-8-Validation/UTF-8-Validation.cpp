#include "main.hpp"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remBytes = 0;
        
        for (int d : data) {
            if (remBytes == 0) {
                if ((d >> 7) == 0b0) {
                    remBytes = 0; // Only 1 byte number.
                }
                else if ((d >> 5) == 0b110) {
                    remBytes = 1; // 1 more byte(number) to be checked, whether it contains starting bits as 10.
                }
                else if ((d >> 4) == 0b1110) {
                    remBytes = 2; // 2 more bytes(numbers) to be checked, whether they contain starting bits as 10.
                }
                else if ((d >> 3) == 0b11110) {
                    remBytes = 3; // 3 more bytes(numbers) to be checked, whether they contain starting bits as 10.
                }
                else {
                    return false;
                }
            }
            else {
                if ((d >> 6) == 0b10) {
                    remBytes--; // Decrement if the following numbers' starting bits are '10'.
                }
                else {
                    return false;
                }
            }
        }
        return remBytes == 0;
    }
};

int main() {
    Solution sln;
    {
        vector<int> data{197, 130, 1};
        assert(true == sln.validUtf8(data));
    }
    {
        vector<int> data{235, 140, 4};
        assert(false == sln.validUtf8(data));
    }
    {
        vector<int> data{255};
        assert(false == sln.validUtf8(data));
    }
    {
        vector<int> data{145};
        assert(false == sln.validUtf8(data));
    }
    return 0;
}