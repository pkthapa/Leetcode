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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;

        while ((nullptr != slow) and
               (nullptr != fast) and
               (nullptr != fast->next)) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Check for loop.
                break;
            }
        }

        // Check if the list contains only one node.
        if ((nullptr == fast) or (nullptr == fast->next)) {
            return {};
        }

        // There is loop, so now increment both slow and head pointer one-step at a time.
        // If there is loop, then both the pointers will definitely meet at the node where the loop starts.
        if (slow == fast) {
            while (slow != head) {
                slow = slow->next;
                head = head->next;
            }
            return head;
        }
        return {};
    }
};

int main() {
    Solution sln;

    {
        auto node = new ListNode(2);
        ListNode* root = new ListNode(3);
        root->next = node;
        root->next->next = new ListNode(0);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = node;
        assert(node == sln.detectCycle(root));
    }
    {
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = root;
        assert(root == sln.detectCycle(root));
    }
    {
        ListNode* root = new ListNode(1);
        assert(nullptr == sln.detectCycle(root));
    }
    return 0;
}