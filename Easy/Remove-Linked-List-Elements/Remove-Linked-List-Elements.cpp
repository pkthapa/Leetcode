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
    ListNode* removeElements(ListNode* head, int val) {
        if (nullptr == head) {
            return nullptr;
        }

        // If the start node is the node to be deleted.
        // Then, loop and proceed to next until you find different value (not to be deleted).
        while (nullptr != head and head->val == val) {
            auto t = head;
            head = head->next;
            delete t;
        }
        
        ListNode* prev = nullptr;
        auto curr = head;

        while (nullptr != curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

void freeList(ListNode* n) {
    while (nullptr != n) {
        auto t = n;
        n = n->next;
        delete t;
    }
}

int main() {
    Solution sln;

    {
        // 1 -> 2 -> 3 -> 4 -> 5
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = new ListNode(5);
        auto t = sln.removeElements(root, 2);
        assert(1 == t->val);
        assert(3 == t->next->val);
        assert(4 == t->next->next->val);
        assert(5 == t->next->next->next->val);
        assert(nullptr == t->next->next->next->next);
        freeList(t);
    }
    {
        // 1 -> 1 -> 1 -> 4 -> 5
        ListNode* root = new ListNode(1);
        root->next = new ListNode(1);
        root->next->next = new ListNode(1);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = new ListNode(5);
        auto t = sln.removeElements(root, 1);
        assert(4 == t->val);
        assert(5 == t->next->val);
        assert(nullptr == t->next->next);
        freeList(t);
    }
    {
        // 1 -> 1 -> 1 -> 1 -> 1
        ListNode* root = new ListNode(1);
        root->next = new ListNode(1);
        root->next->next = new ListNode(1);
        root->next->next->next = new ListNode(1);
        root->next->next->next->next = new ListNode(1);
        auto t = sln.removeElements(root, 1);
        assert(nullptr == t);
        freeList(t);
    }
    {
        ListNode* root = nullptr;
        auto t = sln.removeElements(root, 1);
        assert(nullptr == t);
        freeList(t);
    }
    return 0;
}