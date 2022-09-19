#include "main.hpp"

class Solution {
    // https://www.youtube.com/watch?v=kXy0ABd1vwo&ab_channel=TECHDOSE

    bool isCyclic(vector<vector<int>>& adjList, vector<int>& visited, int curr) {
        // If we try to visite a node in processing state (2), then return false.
        if (visited[curr] == 2) {
            return true;
        }
        
        // Update the state to processing (2).
        visited[curr] = 2;
        
        for (int i = 0; i < adjList[curr].size(); ++i) {
            // If not processed, then check for other nodes in the 'adjList'.
            int currNodeLink = adjList[curr][i];

            if (visited[currNodeLink] != 1) {
                if (isCyclic(adjList, visited, currNodeLink)) {
                    return true;
                }
            }
        }
        
        // Update the state to processed (1).
        visited[curr] = 1;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        // Load adjacency list.
        for (int i = 0; i < prerequisites.size(); ++i) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        // 0 - not visited.
        // 1 - processed.
        // 2 - processing.
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (isCyclic(adjList, visited, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sln;
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites {{1, 0}};
        assert(true == sln.canFinish(numCourses, prerequisites));
    }
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites {{1, 0}, {0, 1}};
        assert(false == sln.canFinish(numCourses, prerequisites));
    }
    {
        int numCourses = 20;
        vector<vector<int>> prerequisites {{0, 10}, {3, 18}, {5, 5}, {6, 11}, {11, 14}, {13, 1}, {15, 1}, {17, 4}};
        assert(false == sln.canFinish(numCourses, prerequisites));
    }
    return 0;
}