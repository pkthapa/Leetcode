#include "main.hpp"

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // Sort the token in increasing order. The highest token will be at the last.
        sort(tokens.begin(), tokens.end()); // TC: O(nlogn)
        
        int l = 0;
        int r = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        
        while (l <= r) {
            if (power >= tokens[l]) {
                score++;
                maxScore = std::max(maxScore, score);
                power -= tokens[l++];
            }
            // If 'power' is not enough then check if we have enough 'score' to get the max power.
            else if (score > 0) {
                score--;
                power += tokens[r--]; // Always get the max power by sacrificing 1 point.
            }
            // If we don't have either enough 'power' or enough 'score', then return 'maxScore' till now.
            else {
                return maxScore;
            }
        }
        return maxScore;
    }
};

int main() {
    Solution sln;
    {
        int power = 50;
        vector<int> tokens{100};
        assert(0 == sln.bagOfTokensScore(tokens, power));
    }
    {
        int power = 150;
        vector<int> tokens{100, 200};
        assert(1 == sln.bagOfTokensScore(tokens, power));
    }
    {
        int power = 200;
        vector<int> tokens{100, 200, 300, 400};
        assert(2 == sln.bagOfTokensScore(tokens, power));
    }
    return 0;
}