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
    int getDecimalValue(ListNode* head) {
        int result {0};

        while (nullptr != head) {
            result = (2 * result) + head->val;
            head = head->next;
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        ListNode* root = new ListNode(1);
        root->next = new ListNode(0);
        root->next->next = new ListNode(1);
        assert(5 == sln.getDecimalValue(root));
    }
    {
        ListNode* root = new ListNode(1);
        root->next = new ListNode(1);
        root->next->next = new ListNode(1);
        assert(7 == sln.getDecimalValue(root));
    }
    {
        ListNode* root = new ListNode(1);
        root->next = new ListNode(1);
        root->next->next = new ListNode(1);
        root->next->next->next = new ListNode(1);
        root->next->next->next->next = new ListNode(1);
        assert(31 == sln.getDecimalValue(root));
    }
    return 0;
}