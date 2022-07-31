#include "main.hpp"

class Solution {
public:
    void calCharOccurences(const string& str, vector<vector<int>>& anagramsList) {
        vector<int> occurencesCount(26, 0);

        for (auto c : str) {
            ++occurencesCount[c - 'a'];
        }
        anagramsList.emplace_back(occurencesCount);
    }

    vector<vector<string>> groupAnagrams(vector<string>&& strs) {
        if (strs.empty()) { return {}; }

        vector<vector<string>> result;

        // Stores the 'strs' array as letter count array.
        // ["eat","tea","tan","ate","nat","bat"] = vector of arrays of alphabets count.
        vector<vector<int>> anagramsList;
        
        for (auto str : strs) {
            // Update the arrays of alphabets count.
            calCharOccurences(str, anagramsList);
        }

        // Create a mappings with key as "count of characters in a string".
        // So, that we can group other strings together.
        map<vector<int>, vector<string>> mappings;
        for (int i = 0; i < anagramsList.size(); ++i) {
            mappings[anagramsList[i]].emplace_back(strs[i]);
        }

        // Now that the mappings are created, now we need to just return the
        // value part of the mappings.
        for (auto mapping : mappings) {
            vector<string> temp;
            for (auto s : mapping.second) {
                temp.emplace_back(s);
            }
            result.emplace_back(temp);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<string>> result {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
        vector<vector<string>> output = sln.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
        assert(result.size() == output.size());

        // Sorting the output and the result to be compared for easy checking.        
        for (auto& strs : result) {
            sort(strs.begin(), strs.end());
        }
        for (auto& strs : output) {
            sort(strs.begin(), strs.end());
        }
        sort(result.begin(), result.end());
        sort(output.begin(), output.end());

        assert(result == output);
    }
    {
        vector<vector<string>> result {{""}};
        assert(result == sln.groupAnagrams({""}));
    }
    {
        vector<vector<string>> result {{"a"}};
        assert(result == sln.groupAnagrams({"a"}));
    }
    return 0;
}