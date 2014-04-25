class Solution {
public:
  bool is_symmetric(TreeNode *left, TreeNode *right) {
    if ((NULL == left) && (NULL == right)) {
      return true;
    }
    else if ((NULL == left) || (NULL == right)) {
      return false;
    }
    else {
      if (left->val == right->val) {
        return (is_symmetric(left->left, right->right) &&
            is_symmetric(left->right, right->left));
      }
      else {
        return false;
      }
    }
  }
  bool isSymmetric(TreeNode *root) {
    if (NULL == root) {
      return true;
    }
    else {
      return is_symmetric(root->left, root->right);
    }
  }
};