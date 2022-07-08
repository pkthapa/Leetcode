#include "main.hpp"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; ++i) {
            res <<= 1; // Make space for the bit that is going to come from LSB of input.
            res |= (n & 1); // Extract the LSB of input and OR with res.
            n >>= 1; // Remove the LSB of input that is processed in previous step.
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;

    assert(964176192 == sln.reverseBits(43261596));
    assert(3221225471 == sln.reverseBits(4294967293));

    return 0;
}
