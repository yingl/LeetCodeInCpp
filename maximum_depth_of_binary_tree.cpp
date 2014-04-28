class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (NULL == root) {
      return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};