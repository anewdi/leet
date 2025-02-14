#include <iostream>
#include <stack>
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
private:
  void inOrder(TreeNode *node, std::vector<int> &vals) {
    if (!node) {
      return;
    }
    inOrder(node->left, vals);
    vals.push_back(node->val);
    inOrder(node->right, vals);
  }

public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> vals;
    inOrder(root, vals);
    return vals;
  }

  // std::vector<int> inorderTraversal(TreeNode *root) {

  //  std::vector<int> vals;
  //  std::stack<TreeNode *> node;

  //  while (root != nullptr || !node.empty()) {
  //    while (root != nullptr) {
  //      node.push(root);
  //      root = root->left;
  //    }

  //    root = node.top();
  //    vals.push_back(root->val);
  //    node.pop();
  //    root = root->right;
  //  }

  //  return vals;
  //};
};

int main() {
  Solution aa;
  TreeNode root(
      1,
      new TreeNode(2, new TreeNode(4),
                   new TreeNode(5, new TreeNode(6), new TreeNode(7))),
      new TreeNode(3, nullptr, new TreeNode(8, new TreeNode(9), nullptr)));
  std::vector<int> vals = aa.inorderTraversal(&root);
  for (int i : vals) {
    std::cout << i << std::endl;
  }
}
