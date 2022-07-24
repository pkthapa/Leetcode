#include "main.hpp"

// Credits: https://www.youtube.com/watch?v=IWXZAvBIuyE&ab_channel=KnowledgeCenter
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize the final vector with 1's.
        vector<int> vec (rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; ++i) {
            // Always attack from last element so that we don't end
            // up modifying the left (starting) elements first. The left
            // elements will be used for calculating new row elements.
            for (int j = i; j > 0; --j) {
                vec[j] = vec[j] + vec[j - 1];
            }
        }

        return vec;
    }
};

int main() {
    Solution sln;
    {
        vector<int> res = {1, 3 , 3 ,1};
        assert(res == sln.getRow(3));
    }
    {
        vector<int> res = {1};
        assert(res == sln.getRow(0));
    }
    {
        vector<int> res = {1, 1};
        assert(res == sln.getRow(1));
    }
    return 0;
}