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
    ListNode* middleNode(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (nullptr != fast and nullptr != fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    Solution sln;

    {
        auto centerNode = new ListNode(3);
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = centerNode;
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = new ListNode(5);
        assert(centerNode == sln.middleNode(root));
    }
    {
        auto centerNode = new ListNode(4);
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = centerNode;
        root->next->next->next->next = new ListNode(5);
        root->next->next->next->next->next = new ListNode(6);
        assert(centerNode == sln.middleNode(root));
    }
    {
        ListNode* root = new ListNode(1);
        assert(root == sln.middleNode(root));
    }
    return 0;
}