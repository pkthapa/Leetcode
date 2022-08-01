#include "main.hpp"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode;
        ListNode* tail = dummy;
        
        while (nullptr != h1 && nullptr != h2) {
            if (h1->val < h2->val) {
                tail->next = h1;
                h1 = h1->next;
            }
            else {
                tail->next = h2;
                h2 = h2->next;
            }
            
            tail = tail->next;
        }
        
        if (nullptr != h1) {
            tail->next = h1;
        }
        else if (nullptr != h2) {
            tail->next = h2;
        }
        return dummy->next;
    }

    ListNode* mergeTwoListsUsingRecursion(ListNode* h1, ListNode* h2) {
        if (nullptr == h1) {
            return h2;
        }
        if (nullptr == h2) {
            return h1;
        }

        // start with the linked list
        // whose head val is the least
        if (h1->val < h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        }

        h2->next = mergeTwoLists(h1, h2->next);
        return h2;
    }
};

int main() {
    Solution sln;
    {
        ListNode* h1 = new ListNode(1);
        h1->next = new ListNode(2);
        h1->next->next = new ListNode(4);

        ListNode* h2 = new ListNode(1);
        h2->next = new ListNode(3);
        h2->next->next = new ListNode(4);

        auto mergedList = sln.mergeTwoLists(h1, h2);

        assert(mergedList->val = 1);
        assert(mergedList->next->val = 1);
        assert(mergedList->next->next->val = 2);
        assert(mergedList->next->next->next->val = 3);
        assert(mergedList->next->next->next->next->val = 4);
        assert(mergedList->next->next->next->next->next->val = 4);
    }
    {
        ListNode* h1 = new ListNode(1);
        h1->next = new ListNode(2);
        h1->next->next = new ListNode(4);

        ListNode* h2 = new ListNode(1);
        h2->next = new ListNode(3);
        h2->next->next = new ListNode(4);

        auto mergedList = sln.mergeTwoListsUsingRecursion(h1, h2);

        assert(mergedList->val = 1);
        assert(mergedList->next->val = 1);
        assert(mergedList->next->next->val = 2);
        assert(mergedList->next->next->next->val = 3);
        assert(mergedList->next->next->next->next->val = 4);
        assert(mergedList->next->next->next->next->next->val = 4);
    }

    return 0;
}