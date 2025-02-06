#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *out = new ListNode();
    ListNode *pout = out;

    while (list1 && list2) {
      if (list1->val > list2->val) {
        pout->next = new ListNode(list2->val);
        list2 = list2->next;
      } else {
        pout->next = new ListNode(list1->val);
        list1 = list1->next;
      }

      pout = pout->next;
    }

    pout->next = list1 ? list1 : list2;

    return out->next;
  };
};

int main() {
  Solution aa;

  ListNode *n1 = new ListNode(-6);
  ListNode *n2 = new ListNode(-5);
  n1->next = n2;
  ListNode *n3 = new ListNode(6);
  n2->next = n3;

  ListNode *n4 = new ListNode(6);
  n3->next = n4;
  ListNode *n5 = new ListNode(7);
  n4->next = n5;

  ListNode *nn = new ListNode(0);

  ListNode *current = aa.mergeTwoLists(n1, nn);
  while (current != nullptr) {
    cout << current->val;
    current = current->next;
  }
}
