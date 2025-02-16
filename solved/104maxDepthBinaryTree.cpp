#include <iostream>
#include <queue>
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
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    // int left = maxDepth(root->left);
    // int right = maxDepth(root->right);
    // return left > right ? left + 1 : right + 1;

    // Alternative solution
    std::queue<TreeNode *> nodes;
    nodes.push(root);

    int depth = 0;
    while (!nodes.empty()) {
      for (int i = 0, u = nodes.size(); i < u; ++i) {
        if (nodes.front()->right) {
          nodes.push(nodes.front()->right);
        }
        if (nodes.front()->left) {
          nodes.push(nodes.front()->left);
        }
        nodes.pop();
      }
      depth++;
    };
    return depth;
  }
};

int main() {
  Solution aa;
  std::cout << aa.maxDepth(new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
}
