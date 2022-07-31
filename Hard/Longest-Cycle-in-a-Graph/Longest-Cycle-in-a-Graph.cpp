#include "main.hpp"

class Solution {
public:
    int ans;
    int cnt;

    void dfs(vector<int>& edges, int u, int c, unordered_map<int, int>& mp1, unordered_map<int, int>& mp2) {
        if(mp1.find(u) != mp1.end()) {
            if(mp2[u] != c) {
                return;
            }
            ans = std::max(cnt - mp1[u], ans);
            return;
        }

        mp1[u] = cnt;
        cnt++;
        mp2[u] = c;

        if(edges[u] != -1){
            dfs(edges, edges[u], c, mp1, mp2);
        }
    }

    int longestCycle(vector<int>&& edges) {
        int n = edges.size();
        unordered_map<int, int> mp1, mp2;
        
        ans = -1;
        cnt = 1;
        int c = 1;
        
        for(int i = 0; i < n; i++) {
            if(mp1.find(i) == mp1.end() && edges[i] != -1) {
                dfs(edges, i, c, mp1, mp2);
                c++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sln;

    assert(3 == sln.longestCycle({3, 3, 4, 2, 3}));

    assert(-1 == sln.longestCycle({2, -1, 3, 1}));

    assert(6 == sln.longestCycle({1, 2, 3, 4, 5, 6, 1}));

    return 0;
}