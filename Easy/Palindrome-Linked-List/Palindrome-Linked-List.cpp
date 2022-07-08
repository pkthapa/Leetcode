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
    /**
     * @brief Recursive approach.
     */
    bool isPalindromeRecursive(ListNode* head, ListNode** temp) {
        if (nullptr == head) {
            return true;
        }
        auto b = isPalindromeRecursive(head->next, temp) and (*temp)->val == head->val;

        // Start updating 'temp' only after 'head' reaches end and stack unwinding starts.
        *temp = (*temp)->next;

        return b;
    }

    bool isPalindromeRecursive(ListNode* head) {
        auto temp = head;

        return isPalindromeRecursive(head, &temp);
    }

    /**
     * @brief Iterative approach.
     */
    bool isPalindromeIterative(ListNode* head) {
        auto slow = head;
        auto fast = head;

        ListNode* prev = nullptr;

        // Keep traversing until 'fast' reaches end.
        // That means, 'slow' is at the center.
        while (nullptr != fast and nullptr != fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // Reverse the list.
            head->next = prev;
            prev = head;
            head = slow;
        }

        // Put 'slow' at the center.
        if (nullptr != fast) {
            slow = slow->next;
        }

        while (nullptr != prev) {
            if (prev->val != slow->val) {
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};

int main() {
    Solution sln;

    {
        // 3 -> 2-> 0 -> 4 -> 3
        ListNode* root = new ListNode(3);
        root->next = new ListNode(2);
        root->next->next = new ListNode(0);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = new ListNode(3);
        assert(false == sln.isPalindromeRecursive(root));
        assert(false == sln.isPalindromeIterative(root));
    }
    {
        // 1 -> 2 -> 1
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(1);
        assert(true == sln.isPalindromeRecursive(root));
        assert(true == sln.isPalindromeIterative(root));
    }
    {
        // 1
        ListNode* root = new ListNode(1);
        assert(true == sln.isPalindromeRecursive(root));
        assert(true == sln.isPalindromeIterative(root));
    }
    return 0;
}