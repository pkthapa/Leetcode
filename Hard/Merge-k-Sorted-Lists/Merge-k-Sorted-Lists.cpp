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

/*
A brute force solution could be to add all elements of the given ‘K’ lists to one list and sort it. If there are a total of ‘N’ elements in all the input lists, then the brute force solution will have a time complexity of O(N*logN) as we will need to sort the merged list. Can we do better than this? How can we utilize the fact that the input lists are individually sorted?

If we have to find the smallest element of all the input lists, we have to compare only the smallest (i.e. the first) element of all the lists. Once we have the smallest element, we can put it in the merged list. Following a similar pattern, we can then find the next smallest element of all the lists to add it to the merged list.

The best data structure that comes to mind to find the smallest number among a set of ‘K’ numbers is a Heap. Let’s see how can we use a heap to find a better algorithm.

1. We can insert the first element of each array in a Min Heap.
2. After this, we can take out the smallest (top) element from the heap and add it to the merged list.
3. After removing the smallest element from the heap, we can insert the next element of the same list into the heap.
4. We can repeat steps 2 and 3 to populate the merged list in sorted order.
*/

class Solution {
    struct myComparator {
        bool operator()(const ListNode* x, const ListNode* y) {
            return x->val > y->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myComparator> minHeap;
        
        // Store only root nodes (if not null) from the lists.
        for (auto root : lists) {
            if (nullptr != root) {
                minHeap.push(root);
            }
        }
        
        // Now take the top element from the minHeap and add it to the merged list (result list).
        // If the top element has next node then add it to the heap.
        ListNode* result = nullptr; // We will be returning the result node, and not the tail node.
        ListNode* tail = nullptr; // To traverse further for adding to the result list by keeping 'result' untouched.
        
        while (!minHeap.empty()) {
            auto t = minHeap.top();
            minHeap.pop();
            
            // Adding the first node.
            if (nullptr == result) {
                result = tail = t;
            }
            else {
                tail->next = t;
                tail = tail->next;
            }
            
            // Add the next node of the poped node.
            if (nullptr != t->next) {
                minHeap.push(t->next);
            }
        }
        return result;
    }
};

/*
// Brute Force approach.

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
};*/

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