class Solution {
public:
  bool is_valid_bst(TreeNode *root, int min, int max) {
    if (NULL == root) {
      return true;
    }

    if ((root->val >= min) && (root->val <= max)) {
      return (is_valid_bst(root->left, min, root->val - 1) &&
          is_valid_bst(root->right, root->val + 1, max));
    }
    else {
      return false;
    }
  }

  bool isValidBST(TreeNode *root) {
    return is_valid_bst(root, INT_MIN, INT_MAX);
  }
};