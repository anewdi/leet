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
    helper(root->left, nodes);
    helper(root->right, nodes);
    nodes.push_back(root->val);
  }

public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<int> nodes;
    // helper(root, nodes);

    std::stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty()) {
      if (!stack.top()) {
        stack.pop();
        if (!stack.top()) {
          while (!stack.top()) {
            stack.pop();
          }
          nodes.push_back(stack.top()->val);
          stack.pop();
        }
        continue;
      }
      TreeNode *last = stack.top();
      stack.push(nullptr);
      stack.push(nullptr);
      stack.push(last->right);
      stack.push(last->left);
    }

    return nodes;
  }
};

int main() {
  Solution aa;

  TreeNode *root =
      new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

  std::vector<int> nodes = aa.postorderTraversal(root);

  for (int node : nodes) {
    std::cout << node << std::endl;
  }
}
