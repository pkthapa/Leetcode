#include "main.hpp"

class Solution {
public:
    // Approach 1: Priority queue.
    // TC: O (nlogn)
    int kthSmallestUsingPriorityQueue(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                pq.push(matrix[i][j]);
            }
        }

        while (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }

    // Approach 2: Binary search.
    // TC: O (logn)
    int kthSmallestUsingBinarySearch(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            int count = lessEqual(matrix, mid);
            if (count < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
    
    // Returns the potential location of a target in the matrix.
    int lessEqual(vector<vector<int>>& matrix, int target) {
        int cnt = 0;
        int N = matrix.size();
        int i = N - 1;
        int j = 0;
        
        while (i >= 0 && j < N) {
            if (matrix[i][j] > target) {
                --i;
            }
            else {
                cnt += i + 1;
                ++j;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sln;
    {
        int k = 8;
        vector<vector<int>> matrix {{ 1,  5,  9},
                                    {10, 11, 13},
                                    {12, 13, 15}};
        assert(13 == sln.kthSmallestUsingPriorityQueue(matrix, k));
        assert(13 == sln.kthSmallestUsingBinarySearch(matrix, k));
    }
    {
        int k = 1;
        vector<vector<int>> matrix {{-5}};
        assert(-5 == sln.kthSmallestUsingPriorityQueue(matrix, k));
        assert(-5 == sln.kthSmallestUsingBinarySearch(matrix, k));
    }
    return 0;
}