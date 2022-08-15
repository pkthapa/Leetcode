#include "main.hpp"

constexpr int8_t MAX_COUNT = 26;

struct TrieNode {
    bool wordEndsHere;
    TrieNode* childPtr[MAX_COUNT]; // Only lowercase English alphabets.
    
    TrieNode() {
        wordEndsHere = false;
        for (int8_t i = 0; i < MAX_COUNT; ++i) {
            childPtr[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        auto curr = root;
        int index = 0;

        for (auto c : word) {
            index = c - 'a';

            if (nullptr == curr->childPtr[index]) {
                curr->childPtr[index] = new TrieNode();
            }
            curr = curr->childPtr[index];
        }
        curr->wordEndsHere = true;
    }
    
    bool search(string word) {
        auto curr = root;
        
        int index = 0;
        for (auto c : word) {
            index = c - 'a';

            if (nullptr == curr->childPtr[index]) {
                return false;
            }
            curr = curr->childPtr[index];
        }
        return curr->wordEndsHere;
    }
    
    bool startsWith(string prefix) {
        int index {0};
        auto curr = root;

        for (auto c : prefix) {
            index = c - 'a';

            if (nullptr == curr->childPtr[index]) {
                return false;
            }
            curr = curr->childPtr[index];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    assert(true == obj->search("apple"));
    assert(false == obj->search("app"));
    assert(true == obj->startsWith("app"));
    obj->insert("app");
    assert(true == obj->search("app"));
    return 0;
}