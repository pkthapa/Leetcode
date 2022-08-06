#include "main.hpp"

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        
        while (pow(minutesToTest / minutesToDie + 1, pigs) < buckets) {
            ++pigs;
        }
        return pigs;
    }
};

int main() {
    Solution sln;

    assert(5 == sln.poorPigs(1000, 15, 60));
    assert(2 == sln.poorPigs(4, 15, 15));
    assert(2 == sln.poorPigs(4, 15, 30));

    return 0;
}