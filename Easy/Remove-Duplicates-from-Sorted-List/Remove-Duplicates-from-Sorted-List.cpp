#include "main.hpp"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto p = head;

    while (p != nullptr and p->next != nullptr) {
      auto q = p->next;

      if (p->val == q->val) {
        p->next = q->next;
        delete q;
      }
      else {
        p = q;
      }
    }
    return head;
  }
};

int main() {
  Solution sln;

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  auto res = sln.deleteDuplicates(head);

  assert(1 == res->val);
  assert(2 == res->next->val);
  assert(4 == res->next->next->val);
  assert(5 == res->next->next->next->val);

  return 0;
}