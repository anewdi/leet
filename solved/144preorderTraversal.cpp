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
  void helper(TreeNode *root, std::vector<int> &nodes) {
    if (!root) {
      return;
    }
    nodes.push_back(root->val);
    helper(root->left, nodes);
    helper(root->right, nodes);
  }

public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> nodes;
    //  helper(root, nodes);

    std::stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty()) {
      if (!stack.top()) {
        stack.pop();
        continue;
      }
      TreeNode *top = stack.top();
      nodes.push_back(top->val);
      stack.pop();
      stack.push(top->right);
      stack.push(top->left);
    }

    return nodes;
  }
};

int main() {
  Solution aa;

  TreeNode *root =
      new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

  std::vector<int> nodes = aa.preorderTraversal(root);

  for (int node : nodes) {
    std::cout << node << std::endl;
  }
}
