#include "main.hpp"

/*
Approach: Topological sorting.

This is how we can implement this algorithm:

a. Initialization

1. We will store the graph in Adjacency Lists, which means each parent vertex will have a list containing all of its children.
We will do this using a HashMap where the ‘key’ will be the parent vertex number and the value will be a List containing children vertices.

2. To find the sources, we will keep a HashMap to count the in-degrees i.e., count of incoming edges of each vertex. Any vertex with ‘0’ in-degree will be a source.

---------------------------------------------------------------------

b. Build the graph and find in-degrees of all vertices

1. We will build the graph from the input and populate the in-degrees HashMap.

---------------------------------------------------------------------

c. Find all sources

1. All vertices with ‘0’ in-degrees will be our sources and we will store them in a Queue.

---------------------------------------------------------------------

d. Sort

1. For each source, do the following things:
- Add it to the sorted list.
- Get all of its children from the graph.
- Decrement the in-degree of each child by 1.
- If a child’s in-degree becomes ‘0’, add it to the sources Queue.

2. Repeat step 1, until the source Queue is empty.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) {
            return false;
        }
        
        // A. Initialize the graph.
        unordered_map<int, int> inDegree; // Count incoming edges of every vertex.
        unordered_map<int, vector<int>> graph; // Adjacency list graph.
        
        for (int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        
        // B. Build the graph.
        for (int i = 0; i < prerequisites.size(); ++i) {
            int parent = prerequisites[i][0], child = prerequisites[i][1];
            
            graph[parent].push_back(child);
            ++inDegree[child];
        }
        
        // C. Find all sources, i.e., vertices with 0 in-degree.
        queue<int> sources;
        for (auto entry : inDegree) {
            if (0 == entry.second) {
                sources.push(entry.first);
            }
        }
        
        vector<int> sortedOrder; // Result.
        
        // D. Add all the 'sources' (source has 0 in-degree) to the 'sortedOrder' (result) and
        // subtract one from all the children's in-degree. If a child's in-degree becomes zero,
        // then add the child to the 'sources' queue.
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
        
        // If the sortedOrder does not contain all tasks (courses), then there is a cyclic dependency between tasks.
        // Hence, we will not be able to schedule all tasks.
        return (sortedOrder.size() == numCourses);
    }
};

/*class Solution {
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
};*/

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