#include "main.hpp"

class Solution {
    // Returns true if there is a cycle.
    // 1: current visiting.
    // 2: visited.
    bool dfs(unordered_map<char, set<char>>& graph, char c, unordered_map<char, int>& visited, string& result) {
        if (visited[c] == 1) {
            return true; // Cycle detected.
        }
        if (visited[c] == 2) {
            return false; // Visited. No further processing.
        }
        
        // Mark visiting.
        visited[c] = 1;
        
        for (auto nextChar : graph[c]) {
            if (dfs(graph, nextChar, visited, result)) {
                return true;
            }
        }

        visited[c] = 2;
        result += c;
        
        return false;
    }

public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char>> graph; // Adjacency list graph.
        unordered_set<char> cSet; // Characters set.
        unordered_map<char, int> visited;
        
        // Collect all the characters given.
        for (auto word : words) {
            for (auto c : word) {
                cSet.insert(c);
            }
        }
        
        // Build the graph.
        for (int i = 0; i < words.size() - 1; ++i) {
            auto& w1 = words[i];
            auto& w2 = words[i + 1];
            
            int sLen = std::min(w1.size(), w2.size());
            int idx = 0;
            
            while (idx < sLen) {
                if (w1[idx] != w2[idx]) {
                    break;
                }
                else {
                    ++idx;
                }
            }
            
            // Invalid input. Not possible because the 2nd word cannot have longer length
            // if the prefixes of w1 and w2 are same.
            if (idx == sLen && w1.size() > w2.size()) {
                return {};
            }
            
            if (idx < sLen) {
                graph[w1[idx]].insert(w2[idx]); // Store in graph.
            }
        }
        
        string result;
        for (auto c : cSet) {
            if (dfs(graph, c, visited, result)) {
                return {};
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<string> v{"wrt", "wrf", "er", "ett", "rftt"};
        assert("wertf" == sln.alienOrder(v));
    }
    {
        vector<string> v{"z", "x"};
        assert("zx" == sln.alienOrder(v));
    }
    {
        vector<string> v{"z", "x", "z"};
        assert("" == sln.alienOrder(v));
    }
    return 0;
}