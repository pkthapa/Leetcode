#include "main.hpp"

/**
* @brief Definition for a binary tree node.
*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    // Create a string from a given tree node.
    void dfsSerialize(TreeNode* node, vector<string>& result) {
        if (nullptr == node) {
            result.emplace_back("N");
            return;
        }
        result.emplace_back(to_string(node->val));

        dfsSerialize(node->left, result);
        dfsSerialize(node->right, result);
    }

    // Create tree from a serialized string.
    TreeNode* dfsDeserialize(vector<string>& nodes, int& offset) {
        if (nodes[offset] == "N") {
            ++offset;
            return nullptr;
        }
        
        auto root = new TreeNode(stoi(nodes[offset]));
        ++offset;
        
        root->left = dfsDeserialize(nodes, offset);
        root->right = dfsDeserialize(nodes, offset);
        
        return root;
    }

    void tokenize(std::string const &str, const char delim, std::vector<std::string> &out)
    {
        size_t start;
        size_t end = 0;

        while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
        {
            end = str.find(delim, start);
            out.push_back(str.substr(start, end - start));
        }
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> result;
        
        dfsSerialize(root, result);
        
        string serializedStr;
        for (auto r : result) {
            serializedStr += r + ",";
        }

        if (serializedStr[serializedStr.size() - 1] == ',') {
            serializedStr.pop_back();
        }
        return serializedStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        tokenize(data, ',', nodes);
        
        int offset = 0;
        return dfsDeserialize(nodes, offset);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    Codec ser, deser;
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(5);
        
        string expected = "1,2,N,N,3,4,N,N,5,N,N";
        assert(expected == ser.serialize(root));

        auto newRoot = deser.deserialize(ser.serialize(root));

        assert(newRoot->val == 1);
        assert(newRoot->left->val == 2);
        assert(newRoot->right->val == 3);
        assert(newRoot->right->left->val == 4);
        assert(newRoot->right->right->val == 5);
    }
    return 0;
}