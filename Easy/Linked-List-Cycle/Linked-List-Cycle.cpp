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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (nullptr != slow &&
               nullptr != fast &&
               nullptr != fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
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
        assert(true == sln.hasCycle(root));
    }
    {
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = root;
        assert(true == sln.hasCycle(root));
    }
    {
        ListNode* root = new ListNode(1);
        assert(false == sln.hasCycle(root));
    }
    return 0;
}