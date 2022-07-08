#include "main.hpp"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;

        for (; i >= 0; --i){
            // If digits[i] is 9, then after incrementing it gives 10.
            // Doing modulo operation on it will tell if the number was actually 9 before incrementing.
            digits[i] = ++digits[i] % 10;

            if (digits[i] != 0){
                return digits;
            }
        }

        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};

int main() {
    Solution sln;

    vector<int> v1 {1, 2, 3}, res1 {1, 2, 4};
    assert(res1 == sln.plusOne(v1));

    vector<int> v2 {4, 3, 2, 1}, res2 {4, 3, 2, 2};
    assert(res2 == sln.plusOne(v2));

    vector<int> v3 {9}, res3 {1, 0};
    assert(res3 == sln.plusOne(v3));

    return 0;
}