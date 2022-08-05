#include "main.hpp"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, uint64_t> dp;
        
        dp[0] = 1;
        
        for (int total = 1; total <= target; ++total) {
            dp[total] = 0;

            for (auto n : nums) {
                dp[total] += (dp.count(total - n) > 0) ?
                              dp[total - n] :
                              0;
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sln;
    {
        int target = 4;
        vector<int> nums {1, 2, 3};
        assert(7 == sln.combinationSum4(nums, target));
    }
    {
        int target = 3;
        vector<int> nums {9};
        assert(0 == sln.combinationSum4(nums, target));
    }
    {
        int target = 999;
        vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111};
        assert(1 == sln.combinationSum4(nums, target));
    }
    return 0;
}