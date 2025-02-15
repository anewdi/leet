#include <iostream>
#include <stack>

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
  bool symmetric(TreeNode *r1, TreeNode *r2) {
    if (!r1 || !r2) {
      return r1 == r2;
    }

    return (r1->val == r2->val) && symmetric(r1->left, r2->right) &&
           symmetric(r1->right, r2->left);
  };

public:
  bool isSymmetric(TreeNode *root) {
    TreeNode *r1, *r2;
    // return symmetric(r1, r2);
    //
    std::stack<TreeNode *> nodes;
    nodes.push(root->right);
    nodes.push(root->left);

    while (!nodes.empty()) {
      r1 = nodes.top();
      nodes.pop();
      r2 = nodes.top();
      nodes.pop();

      if (!r1 && !r2)
        continue;
      if (!r1 || !r2 || r1->val != r2->val) {
        return false;
      }

      nodes.push(r2->right);
      nodes.push(r1->left);
      nodes.push(r2->left);
      nodes.push(r1->right);
    }

    return true;
  };
};

int main() {
  Solution aa;
  TreeNode root(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                new TreeNode(2, new TreeNode(4), new TreeNode(3)));

  std::cout << aa.isSymmetric(&root) << std::endl;
}
