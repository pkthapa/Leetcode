#include "main.hpp"

class Solution {
public:
    int squaredDigitsSum(int n){
        int sum = 0;
        while (n > 0){
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    /**
     * @brief First approach.
     */
    bool isHappy(int n) {
        unordered_set<int> visitedElements;

        while (1 != n){
            n = squaredDigitsSum(n);

            if (1 == n){
                return true;
            }
            if (visitedElements.count(n) == 0){
                visitedElements.insert(n);
            }
            else{
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Second approach.
     * https://www.johndcook.com/blog/2018/03/24/squared-digit-sum/
     */
    bool isHappyWithAttractor(int n) {
        unordered_set<int> attractors {4, 16, 37, 58, 89, 145, 42, 20};
        
        while (n > 0){
            n = squaredDigitsSum(n);
            
            if (n == 1){
                return true;
            }
            if (attractors.count(n) != 0){
                return false;
            }
        }
        return false;
    }

    /**
     * @brief Third approach. Floyd cycle detection.
     */
    bool isHappyWithFloydCycleDetection(int n) {
        auto slow = squaredDigitsSum(n);
        auto fast = squaredDigitsSum(squaredDigitsSum(n));

        while (slow != fast){
            slow = squaredDigitsSum(slow);
            fast = squaredDigitsSum(squaredDigitsSum(fast));
        }

        if (slow == 1){
            return true;
        }
        return false;
    }
};

int main() {
    Solution sln;

    assert(false == sln.isHappy(2));
    assert(false == sln.isHappyWithAttractor(2));
    assert(false == sln.isHappyWithFloydCycleDetection(2));

    assert(true == sln.isHappy(19));
    assert(true == sln.isHappyWithAttractor(19));
    assert(true == sln.isHappyWithFloydCycleDetection(19));

    return 0;
}