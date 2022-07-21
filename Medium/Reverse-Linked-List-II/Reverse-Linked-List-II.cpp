#include "main.hpp"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Credits: https://www.youtube.com/watch?v=RF_M9tX4Eag
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Dummy node approach.
        // Insert a dummy node at the beginning. So, 'dummy' becomes the head.
        auto dummy = new ListNode(0, head);

        // Phase 1: Lets make the curr pointer point to 'left' node.
        auto leftPrev = dummy;
        auto curr = head;
        for (auto i = 0; i < left - 1; ++i) {
            leftPrev = curr;
            curr = curr->next;
        }

        // Phase 2: Now reverse the sub-list (right - left + 1) times.
        ListNode* prev = nullptr;
        for (auto i = 0; i < right - left + 1; ++i) {
            auto tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }

        // Phase 3: Connecting the missing links.
        leftPrev->next->next = curr;
        leftPrev->next = prev;

        return dummy->next;
    }
};

int main() {
    Solution sln;
    {
        // 1 -> 2-> 3 -> 4 -> 5
        int left = 2, right = 4;
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        root->next->next->next->next = new ListNode(5);
        root = sln.reverseBetween(root, left, right);
        assert(1 == root->val);
        assert(4 == root->next->val);
        assert(3 == root->next->next->val);
        assert(2 == root->next->next->next->val);
        assert(5 == root->next->next->next->next->val);
    }
    {
        // 1 -> 2-> 3 -> 4
        int left = 1, right = 4;
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        root = sln.reverseBetween(root, left, right);
        assert(4 == root->val);
        assert(3 == root->next->val);
        assert(2 == root->next->next->val);
        assert(1 == root->next->next->next->val);
    }
    {
        // 1
        int left = 1, right = 1;
        ListNode* root = new ListNode(1);
        root = sln.reverseBetween(root, left, right);
        assert(1 == root->val);
    }
    {
        // 1 -> 2-> 3 -> 4
        int left = 4, right = 4;
        ListNode* root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        root->next->next->next = new ListNode(4);
        root = sln.reverseBetween(root, left, right);
        assert(1 == root->val);
        assert(2 == root->next->val);
        assert(3 == root->next->next->val);
        assert(4 == root->next->next->next->val);
    }
    return 0;
}