#include "main.hpp"

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (nullptr == head || nullptr == head->next) {
            return nullptr;
        }

        auto dummy = new ListNode(0, head);
        auto left = head; // 'left' points the node to be deleted.
        auto right = head;

        while (n-- > 0) {
            right = right->next;
        }
        
        ListNode* prev = dummy;
        while (nullptr != right) {
            prev = left;
            left = left->next;
            right = right->next;
        }
        prev->next = left->next;
        
        delete left;
        left = nullptr;

        return dummy->next;
    }
};

int main() {
    Solution sln;
    {
        int n = 2;
        auto root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = new ListNode(5);
        
        auto result = sln.removeNthFromEnd(root, n);

        assert(result->val = 1);
        assert(result->next->val = 2);
        assert(result->next->next->val = 3);
        assert(result->next->next->next->val = 5);
    }
    {
        int n = 1;
        auto root = new ListNode(1);

        auto result = sln.removeNthFromEnd(root, n);

        assert(result == nullptr);
    }
    {
        int n = 2;
        auto root = new ListNode(1);
        root->next = new ListNode(2);

        auto result = sln.removeNthFromEnd(root, n);

        assert(result->val == 2);
    }
    return 0;
}