#include "main.hpp"

/**
 * @brief Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (nullptr == head) return head;

    ListNode* curr = head;
    ListNode* prev= nullptr;
    ListNode* temp = nullptr;

    while (curr != nullptr){
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }
};

int main() {
  Solution sln;

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  auto temp = head;
  cout << "Input list: ";
  while (nullptr != temp){
    cout << temp->val << " ";
    temp = temp->next;
  }

  auto revList = sln.reverseList(head);

  cout << "\nReversed list: ";
  while (nullptr != revList){
    cout << revList->val << " ";
    revList = revList->next;
  }

  return 0;
}