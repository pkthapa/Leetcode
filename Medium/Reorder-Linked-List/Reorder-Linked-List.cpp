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
     * @brief Approach: Two pointer approach.
     * Traverse using two-pointer approach. When 'fast' reaches end, 'slow' reaches middle.
     * Reverse the second half of the list (starting from 'slow->next').
     * And most importantly, nullify the previous pointer of slow. This detaches the first half.
     * After reversing second half, then merge both the lists.
     */
    void reorderList(ListNode* head) {
        // If list is empty.
        if (nullptr == head) {
            return;
        }

        auto slow = head;
        auto fast = head;
        ListNode* prev = nullptr;

        while (nullptr != fast->next and nullptr != fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        auto head2 = slow->next; // Start node for reversing.
        auto curr = head2;

        slow->next = nullptr; // Disconnect the two list (original and reversed lists).

        prev = nullptr;
        while (nullptr != head2) {
            auto t = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = t;
        }

        head2 = prev;

        // 'head2' is a start node of reversed list.
        // We have 'head' as a start node of original list.
        // We need to iterate and merge until 'head' reaches 'slow'.

        curr = head; // Use 'curr' as a temporary pointer to iterate.
        while (nullptr != curr and nullptr != head2) {
            auto t1 = curr->next;
            auto t2 = head2->next;

            curr->next = head2;
            head2->next = t1;

            curr = t1;
            head2 = t2;
        }

        // 'head' is the start node of the modified list.
    }
};

int main() {
    Solution sln;

    {
        // 1 -> 2-> 3 -> 4 -> 5
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = new ListNode(5);
        sln.reorderList(root);
        assert(1 == root->val);
        assert(5 == root->next->val);
        assert(2 == root->next->next->val);
        assert(4 == root->next->next->next->val);
        assert(3 == root->next->next->next->next->val);
    }
    {
        // 1 -> 2-> 3 -> 4
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        sln.reorderList(root);
        assert(1 == root->val);
        assert(4 == root->next->val);
        assert(2 == root->next->next->val);
        assert(3 == root->next->next->next->val);
    }
    {
        // 1
        ListNode* root = new ListNode(1);
        sln.reorderList(root);
        assert(1 == root->val);
    }

    return 0;
}