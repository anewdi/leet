#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *p1 = head, *p2 = head;

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;

      if (p2 == p1) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution aa;

  ListNode *head = new ListNode(3);
  ListNode *n1 = new ListNode(2);
  head->next = n1;
  ListNode *n2 = new ListNode(0);
  n1->next = n2;
  ListNode *n3 = new ListNode(-4);
  n2->next = n3;
  n3->next = n1;

  std::cout << aa.hasCycle(head) << std::endl;
}
