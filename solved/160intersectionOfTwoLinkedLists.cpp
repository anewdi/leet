#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }

    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;

    while (ptr1 != ptr2) {
      ptr1 = (ptr1 == nullptr) ? headB : ptr1->next;
      ptr2 = (ptr2 == nullptr) ? headA : ptr2->next;
    }
    return ptr1;
  }
};

int main() {
  Solution aa;

  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(999);
  l1->next = l2;

  ListNode *l5 = new ListNode(3);
  ListNode *l6 = new ListNode(3);
  l5->next = l6;
  l6->next = l2;
  ListNode *res = aa.getIntersectionNode(l1, l5);

  std::cout << res << std::endl;
  return 0;
}
