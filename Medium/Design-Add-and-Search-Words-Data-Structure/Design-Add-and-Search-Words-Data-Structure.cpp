#include "main.hpp"

constexpr int8_t MAX_COUNT = 26;

struct TrieNode {
    bool isWordEndsHere;
    TrieNode* children[MAX_COUNT];
    
    TrieNode() {
        isWordEndsHere = false;

        for (int8_t i = 0; i < MAX_COUNT; ++i) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
    TrieNode* root;

    bool searchInNode(string& word, int i, TrieNode* node) {
        if (nullptr == node) {
            return false;
        }

        // If the index 'i' is equal to the length of 'word', then check
        // if the whole word 'word' is entered as the whole word in the trie tree.
        if (i == word.size()) {
            return node->isWordEndsHere;
        }

        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->children[word[i] - 'a']);
        }

        // Backtracking approach to check for multiple '...'.
        for (int8_t j = 0; j < MAX_COUNT; ++j) {
            // If '.' then check for '.' until a valid alphabet is found.
            if (searchInNode(word, i + 1, node->children[j])) {
                return true;
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        auto curr = root;
        int idx = 0;

        for (auto c : word) {
            idx = c - 'a';

            if (nullptr == curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWordEndsHere = true;
    }

    bool search(string word) {
        auto node = root;
        return searchInNode(word, 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    assert(false == obj->search("pad"));
    assert(true == obj->search("bad"));
    assert(true == obj->search(".ad"));
    assert(true == obj->search("b.."));
    return 0;
}