#include "main.hpp"

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Solution {
    TrieNode* root = new TrieNode();

    // Insert into Trie.
    void insert(const string& word) {
        auto node = root;
        
        for (auto c : word) {
            int idx = c - 'a';
            
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isWord = true;
    }

    void search(vector<vector<char>>& board, TrieNode* node, int i, int j, string word, vector<string>& result) {
        // Check boundary conditions.
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') {
            return;
        }
        
        auto c = board[i][j];

        node = node->children[c - 'a'];
        if (nullptr == node) {
            return;
        }
        
        word += board[i][j];
        
        // Check if above 'word' formed from board[i][j] is one of the words in 'words'.
        if (node->isWord) {
            result.emplace_back(word);
            node->isWord = false; // To prevent re-insertion of same word.
        }
        
        board[i][j] = '#'; // Mark as visited.
        
        search(board, node, i + 1, j, word, result);
        search(board, node, i - 1, j, word, result);
        search(board, node, i, j + 1, word, result);
        search(board, node, i, j - 1, word, result);
        
        board[i][j] = c; // Restore.
    }

public:
    vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        for (auto word : words) {
            insert(word);
        }
        
        TrieNode* node = root;
        vector<string> result;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                search(board, node, i, j, "", result);
            }
        }
        return result;
    }
};

/*
// TLE for https://leetcode.com/submissions/detail/833057937/testcase/

class Solution {
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int count) {
        if (count == word.size()) {
            return true; // Word found.
        }
        
        // Check boundary conditions.
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[count] != board[i][j]) {
            return false;
        }
        
        // Back up the current character. In this approach, we will save extra space that would
        // have been consumed by visited board.
        char temp = board[i][j];
        board[i][j] = ' '; // Mark as visited by updating with ' '.
        
        bool found = dfs(board, word, i + 1, j, count + 1) ||
                dfs(board, word, i - 1, j, count + 1) ||
                dfs(board, word, i, j + 1, count + 1) ||
                dfs(board, word, i, j - 1, count + 1);
        
        // Restore the current position on the board.
        board[i][j] = temp;
        return found;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        vector<string> result;
        
        int m = board.size();
        int n = board[0].size();
        
        for (auto word : words) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (word[0] == board[i][j] && dfs(board, word, i, j, 0)) {
                        // Do not already added word.
                        // E.g.
                        // [["o","a","b","n"],
                        //  ["o","t","a","e"],
                        //  ["a","h","k","r"],
                        //  ["a","f","l","v"]]
                        //  ["oa","oaa"]
                        //  In this example, there are two "oa" in horizontal and vertical directions.

                        if (find(result.begin(), result.end(), word) == result.end()) {
                            result.emplace_back(word);
                        }
                    }
                }
            }
        }
        return result;
    }
};
*/

int main() {
    Solution sln;
    {
        vector<string> words {"oath", "pea", "eat", "rain"};
        vector<vector<char>> board {{'o', 'a', 'a', 'n'},
                                    {'e', 't', 'a', 'e'},
                                    {'i', 'h', 'k', 'r'},
                                    {'i', 'f', 'l', 'v'}};
        vector<string> result1 {"eat", "oath"};
        vector<string> result2 {"oath", "eat"};
        auto output = sln.findWords(board, words);
        assert(result1 == output || result2 == output);
    }
    {
        vector<string> words {"abcb"};
        vector<vector<char>> board {{'a', 'b'},
                                    {'c', 'd'}};
        vector<string> result {};
        assert(result == sln.findWords(board, words));
    }
    {
        vector<string> words {"oath", "oaths"};
        vector<vector<char>> board {{'o', 'a', 'a', 'n'},
                                    {'e', 't', 'a', 'e'},
                                    {'i', 'h', 's', 'r'},
                                    {'i', 'f', 'l', 'v'}};
        vector<string> result1 {"oath", "oaths"};
        vector<string> result2 {"oaths", "oath"};
        auto output = sln.findWords(board, words);
        assert(result1 == output || result2 == output);
    }
    return 0;
}