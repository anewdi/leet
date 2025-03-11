#include <iostream>
#include <queue>

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
  int minDepth(TreeNode *root) {
    // Dfs
    if (!root) {
      return 0;
    }
    int right = minDepth(root->right);
    int left = minDepth(root->left);
    return (left == 0 || right == 0) ? left + right + 1
                                     : std::min(right, left) + 1;
  }
  int minDepth2(TreeNode *root) {
    if (!root) {
      return 0;
    }

    std::queue<TreeNode *> nodes;
    nodes.push(root);
    int level = 1;
    while (!nodes.empty()) {
      int size = nodes.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *curNode = nodes.front();
        nodes.pop();
        if (!curNode->left && !curNode->right) {
          return level;
        }
        if (curNode->left) {
          nodes.push(curNode->left);
        }
        if (curNode->right) {
          nodes.push(curNode->right);
        }
      }
      ++level;
    }
    return level;
  }
};

int main() {
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  Solution aa;
  std::cout << aa.minDepth2(root) << std::endl;
}
