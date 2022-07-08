#include "main.hpp"

/**
 * @brief Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (nullptr == headA or nullptr == headB) return nullptr;
    
    // Store in temporary variables so that the start nodes remain intact.
    auto tempA = headA;
    auto tempB = headB;
    
    auto lenA {1}, lenB {1};
    
    while (nullptr != tempA){
      tempA = tempA->next;
      ++lenA;
    }

    while (nullptr != tempB){
      tempB = tempB->next;
      ++lenB;
    }

    tempA = headA;
    tempB = headB;
    auto diff = abs(lenA - lenB);
    
    for (int i = 0; i < diff; ++i){
      if (lenA > lenB){
        tempA = tempA->next;
      }
      else {
        tempB = tempB->next;
      }
    }
    
    // tempA and tempB positions are equidistant from the intersection point.
    while (nullptr != tempA){
      if (tempA != tempB) {
        tempA = tempA->next;
        tempB = tempB->next;
        continue;
      }
      break;
    }
    return tempA;
  }
};

int main() {
  Solution sln;

  auto iNode = new ListNode(3);

  ListNode* head1 = new ListNode(1);
  head1->next = new ListNode(2);
  head1->next->next = iNode;
  head1->next->next->next = new ListNode(4);
  head1->next->next->next->next = new ListNode(5);

  ListNode* head2 = new ListNode(10);
  head2->next = new ListNode(11);
  head2->next->next = new ListNode(12);
  head2->next->next->next = iNode;

  auto temp1 = head1;
  auto temp2 = head2;

  auto intersectionNode = sln.getIntersectionNode(head1, head2);

  assert(temp1 == head1);
  assert(temp2 == head2);

  assert(intersectionNode == iNode);
  assert(intersectionNode->val == iNode->val);

  cout << "Intersection Node val=" << intersectionNode->val << endl;

  return 0;
}