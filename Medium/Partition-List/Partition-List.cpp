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
    // Credits: https://www.youtube.com/watch?v=KT1iUciJr4g
    ListNode* partition(ListNode* head, int x) {
        // Phase 1:
        // Create two lists with dummy nodes: 'left' and 'right'.
        // 'left' holds value less than 'x'.
        // 'right' holds value greater than 'x'.
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);

        // Phase 2: Backups of 'left' and 'right' starts.
        auto leftStart = left;
        auto rightStart = right;

        while (nullptr != head) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            }
            else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        // Phase 3: Clean the last node's next pointer.
        left->next = nullptr;
        right->next = nullptr;

        // Phase 4:
        // i. Merge both the lists.
        // ii. Set the 'head' node.
        left->next = rightStart->next;
        head = leftStart->next;

        return head;
    }
};

int main() {
    Solution sln;
    {
        // Input: 1 -> 4-> 3 -> 2 -> 5 -> 2
        // Output: 1 -> 2 -> 2-> 4 -> 3 -> 5
        int x = 3;
        ListNode* root = new ListNode(1);
        root->next = new ListNode(4);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(2);
        root->next->next->next->next = new ListNode(5);
        root->next->next->next->next->next = new ListNode(2);
        root = sln.partition(root, x);
        assert(1 == root->val);
        assert(2 == root->next->val);
        assert(2 == root->next->next->val);
        assert(4 == root->next->next->next->val);
        assert(3 == root->next->next->next->next->val);
        assert(5 == root->next->next->next->next->next->val);
    }
    {
        // Input: 2 -> 1
        // Output: 1 -> 2
        int x = 2;
        ListNode* root = new ListNode(2);
        root->next = new ListNode(1);
        root = sln.partition(root, x);
        assert(1 == root->val);
        assert(2 == root->next->val);
    }
    return 0;
}