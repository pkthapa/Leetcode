#include "main.hpp"

class Solution {
public:
    /*
    Algorithm:
    1. We can only increment num by converting a digit 6 to 9.
    2. We should always convert the highest digit 6. Suppose num = 669, it has multiple digits 6,
       we must convert the first one to make it 969 rather than 699.
    3. If every digit of num is 9, we only need to return num since it already stands for the largest integer.
    */
    int maximum69Number (int num) {
        string s = to_string(num);
        
        for (auto& c : s) {
            if ('6' == c) {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};

int main() {
    assert(9969 == Solution().maximum69Number(9669));

    assert(9999 == Solution().maximum69Number(9996));

    assert(9999 == Solution().maximum69Number(9999));

    return 0;
}