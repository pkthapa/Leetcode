#include "main.hpp"

// https://www.youtube.com/watch?v=evUFsOb_iLY&t=2s&ab_channel=NeetCode

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        deque<pair<int, char>> q; // pair<index, char>
        
        // Store all 'L's and 'R's in a deque.
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') {
                q.push_front({i, dominoes[i]});
            }
        }

        while (!q.empty()) {
            auto p = q.back();
            q.pop_back();
            
            // Easy for 'L'. Just need to check the left side of 'L'.
            if (p.second == 'L') {
                if (p.first > 0 && dominoes[p.first - 1] == '.') {
                    q.push_front({p.first - 1, 'L'});
                    dominoes[p.first - 1] = 'L';
                }
            }
            // Little tricky for 'R'. Because, we need to check for +2 indices.
            // If next of 'R' is '.' or not, if yes, then check
            // if next-next of 'R' is 'L'.
            else if (p.second == 'R') {
                
                if (p.first + 1 < n && dominoes[p.first + 1] == '.') {
                    
                    if (p.first + 2 < n && dominoes[p.first + 2] == 'L') {
                        // Remove 'L' to save from first if-statement. "if (p.second == 'L')"
                        q.pop_back();
                    }
                    // If not 'L', then we can update next of 'R' to 'R'. That means, current 'R'
                    // can tip off next of 'R'.
                    else {
                        q.push_front({p.first + 1, 'R'});
                        dominoes[p.first + 1] = 'R';
                    }
                }
            }
        }
        return dominoes;
    }
};

int main() {
    Solution sln;
    {
        string dominoes = "RR.L";
        string output = "RR.L";
        assert(output == sln.pushDominoes(dominoes));
    }
    {
        string dominoes = ".L.R...LR..L..";
        string output = "LL.RR.LLRRLL..";
        assert(output == sln.pushDominoes(dominoes));
    }
    return 0;
}