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
    ListNode* deleteMiddle(ListNode* head) {
        // If the link contains only one node.
        if (nullptr != head && nullptr == head->next) {
            delete head;
            return {};
        }

        auto slow = head;
        auto fast = head;
        ListNode* prev = nullptr;
        
        // Find the middle node.
        while (nullptr != fast && nullptr != fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 'slow' points to middle node.
        if (nullptr != prev) {
            prev->next = slow->next;
            delete slow;
        }
        return head;
    }
};

int main() {
    Solution sln;
    {
        ListNode* root = new ListNode(1);
        root->next = new ListNode(3);
        root->next->next = new ListNode(4);
        root->next->next->next = new ListNode(7);
        root->next->next->next->next = new ListNode(1);
        root->next->next->next->next->next = new ListNode(2);
        root->next->next->next->next->next->next = new ListNode(6);

        auto newList = sln.deleteMiddle(root);

        assert(newList->val == 1);
        assert(newList->next->val == 3);
        assert(newList->next->next->val == 4);
        assert(newList->next->next->next->val == 1);
        assert(newList->next->next->next->next->val == 2);
        assert(newList->next->next->next->next->next->val == 6);
    }
    {
        ListNode* root = new ListNode(1);

        auto newList = sln.deleteMiddle(root);

        assert(newList == nullptr);
    }
    {
        ListNode* root = new ListNode(2);
        root->next = new ListNode(1);

        auto newList = sln.deleteMiddle(root);

        assert(newList->val == 2);
        assert(newList->next == nullptr);
    }
    return 0;
}