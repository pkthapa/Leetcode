#include "main.hpp"

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        auto leftA = head; // The left node to be swapped.
        auto leftB = head; // The right node to be swapped.
        auto prevA = dummy;
        auto prevB = dummy;
        auto right = head;

        while (nullptr != right->next) {
            if (k > 1) { // Move only 'leftA' pointer.
                prevA = prevA->next;
                leftA = leftA->next;
                --k;
            }
            else { // Then move 'leftB' pointer.
                prevB = prevB->next;
                leftB = leftB->next;
            }
            right = right->next;
        }

        prevA->next = leftB;
        prevB->next = leftA;

        auto temp = leftB->next;
        leftB->next = leftA->next;
        leftA->next = temp;

        return dummy->next;
    }
};

int main() {
    Solution sln;
    {
        int k = 2;

        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        auto newList = sln.swapNodes(head, k);

        assert(1 == newList->val);
        assert(4 == newList->next->val);
        assert(3 == newList->next->next->val);
        assert(2 == newList->next->next->next->val);
        assert(5 == newList->next->next->next->next->val);
    }
    
    return 0;
}