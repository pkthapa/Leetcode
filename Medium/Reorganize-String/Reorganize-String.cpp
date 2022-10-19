#include "main.hpp"

// Approach: max-heap.
/*
This problem follows the Top ‘K’ Numbers pattern. We can follow a greedy approach to find an arrangement of the given string where no two same characters come next to each other.

We can work in a stepwise fashion to create a string with all characters from the input string. Following a greedy approach, we should first append the most frequent characters to the output strings, for which we can use a Max Heap. By appending the most frequent character first, we have the best chance to find a string where no two same characters come next to each other.

So in each step, we should append one occurrence of the highest frequency character to the output string. We will not put this character back in the heap to ensure that no two same characters are adjacent to each other. In the next step, we should process the next most frequent character from the heap in the same way and then, at the end of this step, insert the character from the previous step back to the heap after decrementing its frequency.

Following this algorithm, if we can append all the characters from the input string to the output string, we would have successfully found an arrangement of the given string where no two same characters appeared adjacent to each other.
*/

class Solution {
    struct myComparator {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            return b.second > a.second;
        }
    };

public:
    string reorganizeString(string s) {
        // Store the frequencies of each character in the string 's'.
        unordered_map<char, int> freqs;
        
        for (auto c : s) {
            ++freqs[c];
        }
        
        // Intuition: Use map-heap to store the all the characters based on their frequencies.
        priority_queue<pair<char, int>, vector<pair<char, int>>, myComparator> maxHeap;
        
        // Add all character-frequency pair to the maxHeap.
        for (auto freq : freqs) {
            maxHeap.push(freq);
        }
        
        string resultString;
        pair<char, int> prevPair(-1, -1);

        while (!maxHeap.empty()) {
            auto p = maxHeap.top();
            maxHeap.pop();
            
            if (prevPair.second > 0) {
                maxHeap.push(prevPair);
            }
            
            resultString += p.first;
            --p.second;
            
            // Store recently poped entry from the heap.
            prevPair = p;
        }
        
        return resultString.size() == s.size() ? resultString : "";
    }
};

int main() {
    Solution sln;
    {
        string s = "aab";
        assert("aba" == sln.reorganizeString(s));
    }
    {
        string s = "aaab";
        assert("" == sln.reorganizeString(s));
    }
    return 0;
}