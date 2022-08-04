#include "main.hpp"

class Solution {
public:
    /* If extension is even, and reflection is odd: receptor 0 is hit.
     * If extension is odd, and reflection is even: receptor 2 is hit.
     * If extension is odd, and reflection is odd: receptor 1 is hit.
     * In the case where both extension and reflection are even, the laser does not hit any receptor.
     */
    int mirrorReflection(int p, int q) {
        int extension = q, reflection = p;
        
        // Loop until both are even.
        while (extension % 2 == 0 && reflection % 2 == 0) {
            extension /= 2;
            reflection /= 2;
        }
        
        if (extension % 2 == 0 && reflection % 2 != 0) {
            return 0;
        }
        if (extension % 2 != 0 && reflection % 2 != 0) {
            return 1;
        }
        if (extension % 2 != 0 && reflection % 2 == 0) {
            return 2;
        }
        return -1;
    }
};

int main() {
    Solution sln;

    assert(2 == sln.mirrorReflection(2, 1));

    assert(1 == sln.mirrorReflection(3, 1));

    return 0;
}