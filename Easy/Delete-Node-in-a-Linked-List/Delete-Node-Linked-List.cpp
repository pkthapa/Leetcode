#include "main.hpp"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        
        // Copy contents pointed by 'temp' to 'node'. That's why we use *temp & *node.
        // Tt means we are copying the content of the pointer.
        *node = *temp;
        delete temp;
    }
};

int main() {
    Solution sln;
    {
        auto node = new ListNode(2);
        ListNode* root = new ListNode(1);
        root->next = node;
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = node;
        sln.deleteNode(node);
        assert(root->val == 1);
        assert(root->next->val == 3);
        assert(root->next->next->val == 4);
    }
    return 0;
}