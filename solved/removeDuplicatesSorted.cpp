#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *ptr = head;

    while (ptr && ptr->next) {
      if (ptr->val == ptr->next->val) {
        ptr->next = ptr->next->next;
      } else {
        ptr = ptr->next;
      }
    }

    return head;
  }
};

int main() {
  Solution aa;
  ListNode *l1 = new ListNode(1), *l2 = new ListNode(1), *l3 = new ListNode(1);
  l1->next = l2;
  l2->next = l3;

  aa.deleteDuplicates(l1);

  ListNode *ptr = l1;
  while (ptr != nullptr) {
    std::cout << ptr->val << std::endl;
    ptr = ptr->next;
  }
}
