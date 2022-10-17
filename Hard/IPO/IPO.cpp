#include "main.hpp"

/*
TWO-HEAP Approach:

1. Add all project capitals to a min-heap, so that we can select a project with the smallest capital requirement.

2. Go through the top projects of the min-heap and filter the projects that can be completed within our available capital. Insert the profits of all these projects into a max-heap, so that we can choose a project with the maximum profit.

3. Finally, select the top project of the max-heap for investment.

4. Repeat the 2nd and 3rd steps for the required number of projects.
*/
class Solution {
    struct capitalCompare {
        bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        }
    };

    struct profitCompare {
        bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
            return x.first < y.first;
        }
    };

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> minCapitalHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, profitCompare> maxProfitHeap;

        int n = profits.size();

        // Insert all project capitals to a min-heap.
        for (int i = 0; i < n; ++i) {
            minCapitalHeap.push({ capital[i], i });
        }
        
        // Let's try to find our answer.
        int availableCapital = w;

        for (int i = 0; i < k; ++i) {
            // Find all projects that can be selected with available capital and insert them in a max-heap.
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
                auto capIndex = minCapitalHeap.top().second;
                minCapitalHeap.pop();
                maxProfitHeap.push({profits[capIndex], capIndex});
            }

            // Terminate if we are unable to find any project that can be completed
            // with the available capital.
            if (maxProfitHeap.empty()) {
                break;
            }

            availableCapital += maxProfitHeap.top().first;
            maxProfitHeap.pop();
        }

        return availableCapital;
    }
};

int main() {
    Solution sln;
    {
        int k = 3;
        int w = 0;
        vector<int> capitals {0, 1, 2, 3};
        vector<int> profits {1, 2, 3, 5};
        assert(8 == sln.findMaximizedCapital(k, w, profits, capitals));
    }
    {
        int k = 3;
        int w = 0;
        vector<int> capitals {0, 1, 2};
        vector<int> profits {1, 2, 3};
        assert(6 == sln.findMaximizedCapital(k, w, profits, capitals));
    }
    return 0;
}