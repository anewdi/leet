#include <iostream>
#include <math.h>

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
private:
  int count(TreeNode *r1) {
    if (!r1) {
      return 0;
    }

    int left = count(r1->left);
    int right = count(r1->right);

    if (left == -1 || right == -1 || abs(left - right) > 1) {
      return -1;
    }

    return std::max(left, right) + 1;
  }

public:
  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }
    return count(root) != -1;
  }
};

int main() {
  TreeNode root(1,
                new TreeNode(2,
                             new TreeNode(3, new TreeNode(4), new TreeNode(4)),
                             new TreeNode(3)),
                new TreeNode(2));

  Solution aa;
  std::cout << aa.isBalanced(&root) << std::endl;
}
