#include "main.hpp"

class Solution {
public:
    void storePath(int node, int distance, vector<int>& edges, vector<int>& path) {
        if (node != -1 && path[node] == -1) {
            path[node] = distance;
            storePath(edges[node], distance + 1, edges, path);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int result = -1;
        int minDistance = INT32_MAX;
        int n = edges.size();
        
        vector<int> path1(n, -1);
        vector<int> path2(n, -1);
        
        storePath(node1, 0, edges, path1);
        storePath(node2, 0, edges, path2);
        
        for (int i = 0; i < n; ++i) {
            int minPath = std::min(path1[i], path2[i]);
            int maxPath = std::max(path1[i], path2[i]);

            if (minPath >= 0 && maxPath < minDistance) {
                minDistance = std::max(path1[i], path2[i]);
                result = i;
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v{2, 2, 3, -1};
        assert(2 == sln.closestMeetingNode(v, 0, 1));
    }
    {
        vector<int> v{1, 2, -1};
        assert(2 == sln.closestMeetingNode(v, 0, 2));
    }
    return 0;
}