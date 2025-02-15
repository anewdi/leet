#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr || q == nullptr) {
      return p == q ? true : false;
    }

    if (p->val != q->val || !isSameTree(p->left, q->left)) {
      return false;
    }

    return isSameTree(p->right, q->right);
  }
};

int main() {
  TreeNode p(
      2, new TreeNode(2, nullptr, new TreeNode(2, new TreeNode(2), nullptr)),
      new TreeNode(2));
  TreeNode q(2, new TreeNode(2, new TreeNode(2), nullptr),
             new TreeNode(2, new TreeNode(2), nullptr));
  Solution aa;
  std::cout << aa.isSameTree(&p, &q);
}
