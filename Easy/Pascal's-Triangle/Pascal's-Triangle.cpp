#include "main.hpp"

class Solution {
public:
    // Let's visualize the triangle as below (left aligned):
    /*
     * 1
     * 1 1
     * 1 2 1
     * 1 3 3 1
     * 1 4 6 4 1
     */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows, vector<int>());

        // Base case: the first element is always '1'.
        result[0] = vector<int>{1};

        for (int i = 1; i < numRows; ++i) {
            vector<int> prevRow = result[i - 1];
            vector<int> currRow(prevRow.size() + 1); // Current row's size will be 1 larger than the previous row's size.

            // First row element is always '1'.
            currRow[0] = 1;

            // Each triangle element (other than the first and last of each row)
            // is equal to the sum of the elements above-and-to-the-left and
            // above-and-to-the-right.
            for (int j = 1; j < prevRow.size(); ++j) {
                currRow[j] = prevRow[j - 1] + prevRow[j];
            }

            // Last row element is always '1'.
            currRow[prevRow.size()] = 1;

            result[i] = currRow; // Update the result.
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> res = {{1}, {1, 1}, {1, 2 , 1}, {1, 3 , 3 ,1}, {1, 4 , 6 , 4 , 1}};
        assert(res == sln.generate(5));
    }
    {
        vector<vector<int>> res = {{1}};
        assert(res == sln.generate(1));
    }
    return 0;
}