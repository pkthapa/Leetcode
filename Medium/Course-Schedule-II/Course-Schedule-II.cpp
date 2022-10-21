#include "main.hpp"

// Approach: Topological sorting.

// Solution is similar to https://leetcode.com/problems/course-schedule/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) {
            return {};
        }
        
        // A. Init the graph.
        unordered_map<int, int> inDegree; // In-degree count of a vertex.
        unordered_map<int, vector<int>> graph; // Adjacency list graph.
        
        for (int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        
        // B. Build the graph.
        for (int i = 0; i < prerequisites.size(); ++i) {
            int parent = prerequisites[i][1], child = prerequisites[i][0];
            
            ++inDegree[child];
            graph[parent].push_back(child);
        }
        
        // C. Find all sources (i.e., vertices with 0 in-degree).
        queue<int> sources;
        for (auto entry : inDegree) {
            if (0 == entry.second) {
                sources.push(entry.first);
            }
        }
        
        vector<int> sortedOrder;
        
        // D. Add each source in 'sortedOrder' and subtract 1 from all of its children's in-degree.
        // If the in-degree becomes 0, then add the child to the 'sources' (because now the children has become source with 0 in-degree).
        while (!sources.empty()) {
            auto vertex = sources.front();
            sources.pop();
            
            sortedOrder.push_back(vertex);
            
            vector<int> children = graph[vertex];
            
            for (auto child : children) {
                --inDegree[child];
                
                if (0 == inDegree[child]) {
                    sources.push(child);
                }
            }
        }
        
        if (sortedOrder.size() != numCourses) {
            return {};
        }
        return sortedOrder;
    }
};

int main() {
    Solution sln;
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites {{1, 0}};
        vector<int> result {0, 1};
        assert(result == sln.findOrder(numCourses, prerequisites));
    }
    {
        int numCourses = 4;
        vector<vector<int>> prerequisites {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        vector<int> result1 {0, 2, 1, 3};
        vector<int> result2 {0, 1, 2, 3};
        auto result = sln.findOrder(numCourses, prerequisites);
        assert(result2 == result || result1 == result);
    }
    {
        int numCourses = 1;
        vector<vector<int>> prerequisites;
        vector<int> result {0};
        assert(result == sln.findOrder(numCourses, prerequisites));
    }
    return 0;
}