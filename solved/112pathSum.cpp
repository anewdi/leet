#include <csignal>
#include <iostream>

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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }

    if (!root->left && !root->right) {
      return targetSum - root->val == 0;
    }

    targetSum -= root->val;

    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
  }
};

int main() {
  Solution aa;

  TreeNode *root = new TreeNode(
      5,
      new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)),
                   nullptr),
      new TreeNode(8, new TreeNode(13),
                   new TreeNode(4, nullptr, new TreeNode(1))));

  std::cout << aa.hasPathSum(root, 22) << std::endl;
}
