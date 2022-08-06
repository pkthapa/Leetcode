#include "main.hpp"

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0);
        auto tail = dummy;
        
        while (nullptr != l1 && nullptr != l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (nullptr != l1) {
            tail->next = l1;
        }
        if (nullptr != l2) {
            tail->next = l2;
        }
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        // We need to iterate over until the length/size of the
        // list 'lists' becomes '1'.
        while (lists.size() > 1) {
            // Will hold the merged lists from list 'lists'.
            vector<ListNode*> mergedLists;
            
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = nullptr;

                // Boundary check for 'l2'. Since we are jumping offset twice,
                // we need to see if 'l2' is within the limit.
                if (i + 1 < lists.size()) {
                    l2 = lists[i + 1];
                }

                // Store the merged lists into 'mergedLists'.
                mergedLists.emplace_back(merge2Lists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};

int main() {
    Solution sln;
    {
        auto l1 = new ListNode(1);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(5);
        
        auto l2 = new ListNode(1);
        l2->next = new ListNode(3);
        l2->next->next = new ListNode(4);

        auto l3 = new ListNode(2);
        l3->next = new ListNode(6);

        vector<ListNode*> lists {l1, l2, l3};
        auto result = sln.mergeKLists(lists);

        assert(result->val == 1);
        assert(result->next->val == 1);
        assert(result->next->next->val == 2);
        assert(result->next->next->next->val == 3);
        assert(result->next->next->next->next->val == 4);
        assert(result->next->next->next->next->next->val == 4);
        assert(result->next->next->next->next->next->next->val == 5);
        assert(result->next->next->next->next->next->next->next->val == 6);
    }
    
    return 0;
}